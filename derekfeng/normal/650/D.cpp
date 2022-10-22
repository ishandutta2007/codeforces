#include<bits/stdc++.h>
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second
void read(int &x){
	register char ch=getchar();x=0;
	for(;ch==' '||ch=='\n';ch=getchar());
	for(;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0'); 
}
int n,m,a[400004],ans[400004],cnt,lis[400004],cur;
vector<pii>ord[400004];
map<int,int>mp;
int L[1600004],R[1600005],dat[1600005],maxlis;
bool ok[400004];
int built_tree(int l,int r){
	int id=++cur;
	if(l!=r)L[id]=built_tree(l,(l+r)/2),R[id]=built_tree((l+r)/2+1,r);
	return id;
}
void upd_max(int id,int l,int r,int pos,int x,bool wif){
	if(l==r){
		if(wif)dat[id]=max(dat[id],x);
		else dat[id]=wif;
	}else{
		if(pos<=(l+r)/2) upd_max(L[id],l,(l+r)/2,pos,x,wif);
		else upd_max(R[id],(l+r)/2+1,r,pos,x,wif);
		dat[id]=max(dat[L[id]],dat[R[id]]);
	}
}
int got(int id,int l,int r,int a,int b){
	if(r<a||b<l)return 0;
	if(a<=l&&r<=b)return dat[id];
	return max(got(L[id],l,(l+r)/2,a,b),got(R[id],(l+r)/2+1,r,a,b));
}
void memset_tree(int id,int l,int r){
	dat[id]=0;
	if(l!=r)memset_tree(L[id],l,(l+r)/2),memset_tree(R[id],(l+r)/2+1,r);
}
vector<int>opr[400004];
int main(){
	read(n),read(m);
	for(int i=1;i<=n;i++){
		read(a[i]),mp[a[i]]=1;
	}
	for(int i=1;i<=m;i++){
		int x,y;read(x),read(y),mp[y]=1;
		ord[x].push_back(mkp(y,i));
	}
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)(it->second)=++cnt;
	for(int i=1;i<=n;i++)a[i]=mp[a[i]];
	for(int i=1;i<=n;i++)
		for(int j=0;j<ord[i].size();j++)ord[i][j].fi=mp[ord[i][j].fi];
	built_tree(1,cnt);
	for(int i=1;i<=n;i++){
		lis[i]=1+got(1,1,cnt,1,a[i]-1);
		opr[lis[i]].push_back(i);
		maxlis=max(lis[i],maxlis);
		for(int j=0;j<ord[i].size();j++)ans[ord[i][j].se]=1+got(1,1,cnt,1,ord[i][j].fi-1);
		upd_max(1,1,cnt,a[i],lis[i],1);
	}
	memset_tree(1,1,cnt);
	for(int i=n;i>=1;i--){
		int ret=1+got(1,1,cnt,a[i]+1,cnt);
		for(int j=0;j<ord[i].size();j++)ans[ord[i][j].se]+=got(1,1,cnt,ord[i][j].fi+1,cnt);
		upd_max(1,1,cnt,a[i],ret,1);
	}
	vector<int>rt[2];
	cur=1;
	memset_tree(1,1,cnt);
	for(int i=maxlis;i>=1;i--){
		cur^=1,rt[cur].clear();
		if(i==maxlis){
			for(int j=0;j<opr[i].size();j++)rt[cur].push_back(opr[i][j]);
		}else{
			for(int j=0;j<rt[cur^1].size();j++)upd_max(1,1,cnt,a[rt[cur^1][j]],rt[cur^1][j],1);
			for(int j=0;j<opr[i].size();j++)if(got(1,1,cnt,a[opr[i][j]]+1,cnt)>opr[i][j])rt[cur].push_back(opr[i][j]);
			for(int j=0;j<rt[cur^1].size();j++)upd_max(1,1,cnt,a[rt[cur^1][j]],rt[cur^1][j],0);
		}
		if(rt[cur].size()<2)ok[rt[cur][0]]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<ord[i].size();j++){
			if(ok[i])ans[ord[i][j].se]=max(ans[ord[i][j].se],maxlis-1);
			else ans[ord[i][j].se]=max(ans[ord[i][j].se],maxlis);
		}
	for(int i=1;i<=m;i++)write(ans[i]),puts("");
}
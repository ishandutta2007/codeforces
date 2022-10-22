#include<bits/stdc++.h>
using namespace std;
const int N=3e5+4,S=(1<<20)+4,inf=1e6;
int n,d,q,m,a[N],b[N];
int rt,ch[N][2],num[N];
int ld[N],rd[N],w[N];
vector<int>all,Ld[N],Rd[N];
int mn[S],tg[S],LL,RR,MN;
int bs(int x){return lower_bound(all.begin(),all.end(),x)-all.begin();}
void get_ct(){
	for(int i=1;i<=n;i++)ch[i][0]=ch[i][1]=0;stack<int>sta;
	for(int i=1;i<=n;i++){
		int lst=0;while(!sta.empty()&&a[sta.top()]<a[i])lst=sta.top(),sta.pop();
		if(!sta.empty())ch[sta.top()][1]=i;ch[i][0]=lst,sta.push(i);
	}while(!sta.empty())rt=sta.top(),sta.pop();
}
void dfs(int x){
	if(b[x]!=0)ld[x]=max(ld[x],b[x]),rd[x]=min(rd[x],b[x]);else d++;
	if(ch[x][0])rd[ch[x][0]]=rd[x],dfs(ch[x][0]),ld[x]=max(ld[x],ld[ch[x][0]]);
	if(ch[x][1])rd[ch[x][1]]=rd[x],dfs(ch[x][1]),ld[x]=max(ld[x],ld[ch[x][1]]);
}
void upd(int i,int l,int r,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){mn[i]+=x,tg[i]+=x;return;}
	int md=(l+r)>>1;upd(i<<1,l,md,a,b,x),upd(i<<1|1,md+1,r,a,b,x);
	mn[i]=min(mn[i<<1],mn[i<<1|1])+tg[i];
}
void sol(){
	scanf("%d%d",&n,&q);for(int i=1;i<=n;i++)scanf("%d",&a[i]);get_ct();
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),ld[i]=-inf,rd[i]=inf;
	d=0,all.clear(),dfs(rt);for(int i=1;i<d;i++)scanf("%d",&w[i]),all.push_back(w[i]);
	bool flg=0;for(int i=1;i<=n;i++)flg|=ld[i]>rd[i];
	if(flg){while(q--){int x;scanf("%d",&x);puts("NO");}return;}
	for(int i=1;i<=n;i++)if(b[i])all.push_back(b[i]);all.push_back(-inf),all.push_back(inf);
	sort(all.begin(),all.end()),all.erase(unique(all.begin(),all.end()),all.end());m=all.size();
	for(int i=0;i<m;i++)num[i]=0,Rd[i].clear(),Ld[i].clear();for(int i=1;i<d;i++)num[bs(w[i])]++;
	for(int i=1;i<=n;i++)if(b[i]==0){int L=bs(ld[i]),R=bs(rd[i]);Rd[L].push_back(R),Ld[R].push_back(L);}
	int D=min(n<<2,S);
	LL=MN=inf,RR=-1;
	memset(mn,0,D<<2),memset(tg,0,D<<2);
	for(int i=0;i<m;i++){
		upd(1,0,m-1,0,i,num[i]);
		for(auto x:Ld[i])upd(1,0,m-1,0,x,-1);
		if(mn[1]<0&&LL==inf)LL=all[i];
		MN=min(MN,mn[1]);
	}
	memset(mn,0,D<<2),memset(tg,0,D<<2);
	for(int i=m-1;~i;i--){
		upd(1,0,m-1,i,m-1,num[i]);
		for(auto x:Rd[i])upd(1,0,m-1,x,m-1,-1);
		if(mn[1]<0){RR=all[i];break;}
	}
	while(q--){
		int x;scanf("%d",&x);
		puts((MN<-1||LL<x||RR>x)?"NO":"YES");
	}
}
int main(){int tc;scanf("%d",&tc);while(tc--)sol();}
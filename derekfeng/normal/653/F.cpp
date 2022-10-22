#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int AD=5e5;
int nxt[1000004][2],len[1000004],fa[1000004],flg[1000004];
int lst=1,cnt=1;
char str[500004];
void ins(int c,int r){
	int p=lst;int np=lst=++cnt;flg[np]=r;
	len[np]=len[p]+1;
	for(;p&&!nxt[p][c];p=fa[p])nxt[p][c]=np;
	if(!p)fa[np]=1;
	else{
		int q=nxt[p][c];
		if(len[q]==len[p]+1)fa[np]=q;
		else{
			int nq=++cnt;
			for(int i=0;i<2;i++)nxt[nq][i]=nxt[q][i];
			fa[nq]=fa[q];
			len[nq]=len[p]+1,fa[q]=fa[np]=nq;
			for(;p&&nxt[p][c]==q;p=fa[p])nxt[p][c]=nq; 
		}
	}
}
vector<int>g[1000004];
int N,n,ld[1000004],rd[1000004];
vector<int>qry[500004];
void dfs(int x){
	for(auto y:g[x])dfs(y),flg[x]=flg[y];
	if(x>1){
		++n;ld[n]=len[fa[x]]+1,rd[n]=len[x];
		qry[flg[x]].push_back(n);
	}
}
int num[500004];
int dat[1148576];
void built(int l,int r,int id){
	dat[id]=1e9;
	if(l<r){
		int mid=(l+r)>>1;
		built(l,mid,id<<1),built(mid+1,r,id<<1|1);
	}
}
void upd(int l,int r,int id,int pos,int x){
	dat[id]=min(dat[id],x);
	if(l<r){
		int mid=(l+r)>>1;
		if(pos<=mid)upd(l,mid,id<<1,pos,x);
		else upd(mid+1,r,id<<1|1,pos,x);
	}
}
int ask(int l,int r,int id,int a,int b){
	if(r<a||b<l)return 1e9;
	if(a<=l&&r<=b)return dat[id];
	int mid=(l+r)>>1;
	return min(ask(l,mid,id<<1,a,b),ask(mid+1,r,id<<1|1,a,b));
}
vector<int>v[1000004];
int s[1000004];
ll ans;
int main(){
	scanf("%d%s",&N,str+1);
	for(int i=1;i<=N;i++)ins(str[i]-'(',i);
	for(int i=2;i<=cnt;i++)g[fa[i]].push_back(i);
	dfs(1);
	num[0]=AD;
	built(1,N,1);
	v[AD].push_back(0); 
	for(int i=1;i<=N;i++){
		num[i]=num[i-1];
		if(str[i]=='(')num[i]++;
		else num[i]--;
		while(s[num[i]]<v[num[i]].size()){
			int tmp=v[num[i]][s[num[i]]];
			if(ask(1,N,1,tmp+1,i)<num[i])s[num[i]]++;
			else break;
		}
		if(s[num[i]]!=v[num[i]].size()){
			for(auto x:qry[i]){
				int LL=i-rd[x],RR=i-ld[x];
				if(RR<v[num[i]][s[num[i]]])continue;
				LL=lower_bound(v[num[i]].begin(),v[num[i]].end(),LL)-v[num[i]].begin();
				RR=upper_bound(v[num[i]].begin(),v[num[i]].end(),RR)-v[num[i]].begin();
				LL=max(LL,s[num[i]]);
				ans+=RR-LL;
			}
		}
		v[num[i]].push_back(i),upd(1,N,1,i,num[i]); 
	}
	printf("%lld",ans);
}
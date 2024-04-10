#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=2e5+10,MAXM=500;
int n,m,lim,x[MAXN],y[MAXN],op[MAXN],idx[MAXN],ed[MAXN],pre[MAXN],bucket[MAXN];
int d[MAXN];
int sum[MAXM][MAXM];
void update(int x,int y,int val){
	if(x>y)return;
	d[x]+=val;d[y+1]-=val;
}
int num(int i,int j){
	return (i-1)%j+1;
}
void solve1(){
	rep(i,1,m){
		if(op[i]==2)continue;
		update(i,ed[i]-1,1);
		int u=idx[i];
		if(x[u]+y[u]<=lim)continue;
		//brute force
		int pos=i;
		while(pos<ed[i]){
			update(pos,min(pos+x[u]-1,ed[i]-1),-1);
			pos+=(x[u]+y[u]);	
		}
	}
	rep(i,1,m)d[i]+=d[i-1];
}
void solve2(int pos,int idx,int f){
//	printf("lim:%d %d\n",lim,x[idx],y[idx]);
	if(x[idx]+y[idx]>lim)return;
//	printf("pos:%d idx:%d f:%d\n",pos,idx,f);
	int a=x[idx],b=y[idx];
	int s=num(pos,a+b),t=num(pos+a-1,a+b);
	if(s<=t){
		rep(i,s,t)sum[a+b][i]+=f;
	}else{
		rep(i,s,a+b)sum[a+b][i]+=f;
		rep(i,1,t)sum[a+b][i]+=f;
	}
}
void calc(int idx){
	int ans=d[idx];
	rep(i,1,lim)ans-=sum[i][num(idx,i)];
	printf("%d\n",ans);
}
int main(){
	scanf("%d%d",&n,&m);
	lim=sqrt(m)+1;
	rep(i,1,n){scanf("%d%d",&x[i],&y[i]);}
	rep(i,1,m){
		scanf("%d%d",&op[i],&idx[i]);
		ed[i]=m+1;
	}
	rep(i,1,m){
		if(op[i]==1)bucket[idx[i]]=i;
		else ed[bucket[idx[i]]]=i,pre[i]=bucket[idx[i]];
	}
	solve1();	
	
	rep(i,1,m){
		if(op[i]==1){
			solve2(i,idx[i],1);
		}else{
			solve2(pre[i],idx[i],-1);
		}
		calc(i);	
	}

	return 0;
}
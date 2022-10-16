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
const ll MAXN=22,MAXM=4e5+10,INF=1e16;
int n,len[MAXN],sum[MAXN][MAXM],pre[MAXN][MAXM];
ll f[(1<<20)+5],ans;
char s[MAXN][MAXM];
vector<int>occ[MAXN][MAXM];
void update(int i,int s,int j){
	int L=1,R=len[j],pos=1e9,ret=0;
	while(L<=R){
		int mid=(L+R)>>1;
		if(pre[j][mid]<-s){
			pos=mid;
			R=mid-1;
		}else{
			L=mid+1;
		}
	}
	ret=lower_bound(occ[j][s].begin(),occ[j][s].end(),pos)-occ[j][s].begin();
	ans=max(ans,f[i]+ret);
	if(pos==1e9)f[i|(1<<(j-1))]=max(f[i|(1<<(j-1))],f[i]+ret);
}
void dp(){
	rep(i,0,(1<<n)-1){
		int s=0;
		rep(j,0,n-1)if((i>>j)&1)s+=sum[j+1][len[j+1]];
		if(s<0)continue;
		rep(j,0,n-1)if(!((i>>j)&1))update(i,s,j+1);
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%s",s[i]+1);
		len[i]=strlen(s[i]+1);
	}
	rep(i,1,n){
		pre[i][0]=1e9;
		rep(j,1,len[i]){
			sum[i][j]=sum[i][j-1];
			if(s[i][j]=='(')sum[i][j]++;
			else sum[i][j]--;
			pre[i][j]=min(pre[i][j-1],sum[i][j]);
		}
		rep(j,1,len[i]){
			if(sum[i][j]<=0)occ[i][-sum[i][j]].pb(j);
		}
	}
	rep(i,1,(1<<n)-1)f[i]=-INF;
	ans=0;
	dp();
	rep(i,1,(1<<n)-1)ans=max(ans,f[i]);
	printf("%lld",ans);
	return 0;
}
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
const int MAXN=10,MAXM=58,INF=1e9;
int T,n,len[MAXN];
int occ[MAXN][MAXM][2];
char s[MAXN][MAXM*2];
int a[MAXN][MAXM*2];
int f[MAXM][1<<MAXN],vis[MAXM][1<<MAXN],ans;
int pre[MAXM][1<<MAXN][2];
int dfs(int i,int mask){
	if(vis[i][mask])return f[i][mask];
	vis[i][mask]=1;
	//
	int& ret=f[i][mask];
	rep(j,0,n-1){
		int pos=0;
		if(mask>>j&1)pos=1; 
		if(!occ[j][i][pos])return ret=0; // 
	} 
	ret=1;
	rep(k,1,52){
		int flag=1,mask2=0;
		//mask
		rep(j,0,n-1){
			int pos=0;
			if(mask>>j&1)pos=1;
			pos=occ[j][i][pos];
			if(occ[j][k][1] && occ[j][k][1]<pos){
				mask2^=(1<<j);
			}else if(!occ[j][k][0] || occ[j][k][0]>=pos)flag=0;				
		}	
		if(!flag)continue;
	//	printf("valid %d\n",k);
		if(1+dfs(k,mask2)>ret){
			ret=1+dfs(k,mask2);
			pre[i][mask][0]=k;
			pre[i][mask][1]=mask2;	 
		}
	}
//	printf("dp[%d][%d]:%d\n",i,mask,ret);
	return ret;
}
void solve(int i,int mask){
	if(pre[i][mask][0])solve(pre[i][mask][0],pre[i][mask][1]);
	if(i<=26)printf("%c",'a'+i-1);
	else printf("%c",'A'+i-27);
}
void solve(){
	memset(f,0,sizeof f);
	memset(vis,0,sizeof vis); 
	memset(occ,0,sizeof occ);
	memset(pre,0,sizeof pre);
	cin>>n;
	rep(i,0,n-1){
		cin>>(s[i]+1);
		len[i]=strlen(s[i]+1);
		rep(j,1,len[i]){
			if(islower(s[i][j]))a[i][j]=s[i][j]-'a'+1;
			else a[i][j]=s[i][j]-'A'+27;
			if(occ[i][a[i][j]][0])occ[i][a[i][j]][1]=j;
			else occ[i][a[i][j]][0]=j; 
		}
	}

	ans=-INF;
	int x=0,y=0;
	rep(i,1,52)rep(j,0,(1<<n)-1){
		if(dfs(i,j)>ans){
			ans=dfs(i,j);
			x=i;y=j;
		}
	}
//	ans=max(ans,dfs(5,0));
	printf("%d\n",ans);
	if(ans!=0)solve(x,y);printf("\n");
}
int main(){
	cin>>T;
	while(T--){
		solve();
	}

	return 0;
}
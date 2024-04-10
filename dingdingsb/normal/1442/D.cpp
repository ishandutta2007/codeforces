#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=3100;
int n,k;
int v[N],w[N];
vector<int>a[N];
vector<int>dp;
int ans=0;
void solve(int l,int r){
	if(l==r){
		//chkmx(ans,dp[k]);
		for(int i=0,sum=0;i<k&&i<a[l].size();i++){
			sum+=a[l][i];
			chkmx(ans,sum+dp[k-i-1]);
		}
		return;
	}
	vector<int>tmp=dp;
	for(int i=l;i<=mid;i++){
		for(int j=k;j>=v[i];j--)
			chkmx(dp[j],dp[j-v[i]]+w[i]);
	}
	solve(mid+1,r);
	dp=tmp;
	for(int i=mid+1;i<=r;i++){
		for(int j=k;j>=v[i];j--)
			chkmx(dp[j],dp[j-v[i]]+w[i]);
	}
	solve(l,mid);
}
signed main(){
	read(n,k);
	for(int i=1;i<=n;i++){
		int x;read(v[i]);a[i].resize(v[i]);
		for(int j=0;j<v[i];j++)
			read(a[i][j]),w[i]+=a[i][j];;
	}
	dp.resize(k+1);
	solve(1,n);
	write(ans);
}
// Problem: F. Defender of Childhood Dreams
// Contest: Codeforces - Codeforces Round #749 (Div. 1 + Div. 2, based on Technocup 2022 Elimination Round 1)
// URL: https://codeforces.com/contest/1586/problem/F
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define pc putchar
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
//#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=1e3+100,M=100;
int n,k,cnt=0;
int col[N][N];
void dfs(int l,int r,int dep){
	chkmx(cnt,dep);
	if(r-l+1<=k){
		for(int i=l;i<=r;i++)
			for(int j=i+1;j<=r;j++)
				col[i][j]=dep;
		return;
	}
	int block=(r-l)/k+1;
	for(int i=0;i<k;i++){
		int ll=l+i*block,rr=min(r,l+(i+1)*block-1);
		for(int j=ll;j<=rr;j++)for(int k=rr+1;k<=r;k++)
			col[j][k]=dep;
		dfs(ll,rr,dep+1);
	}
}
signed main(){
	read(n,k);
	dfs(1,n,1);
	write(cnt);pc('\n');
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			write(col[i][j]),pc(' ');
	
}
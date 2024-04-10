// Problem: E. Rescue Niwen!
// Contest: Codeforces - Codeforces Round #741 (Div. 2)
// URL: https://codeforces.com/contest/1562/problem/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
const int N=1e4+10;
int dp[N];
int t,n;char s[N];
int lcp[N][N];
int cmp(int x,int y){
	//return s[x,n]>s[y,n]
	return s[x+lcp[x][y]]>s[y+lcp[x][y]];
}
void solve(){
	read(n);scanf("%s",s+1);
	for(int i=n+1;i;i--)for(int j=n+1;j;j--)lcp[i][j]=0;
	for(int i=n;i;i--)
		for(int j=n;j;j--){
			lcp[i][j]=s[i]==s[j];
			if(lcp[i][j])lcp[i][j]+=lcp[i+1][j+1];
		}
	dp[1]=n;int ans=n;
	for(int i=2;i<=n;i++){
		dp[i]=n-i+1;
		for(int j=1;j<i;j++){
			if(cmp(i,j)){
				chkmx(dp[i],dp[j]+n-i+1-lcp[i][j]);
			}
		}
		chkmx(ans,dp[i]);
	}
	printf("%d\n",ans);
}
signed main(){
	read(t);while(t--)solve();
}
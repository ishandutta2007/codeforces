// Problem: F. RBS
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL: https://codeforces.ml/contest/1598/problem/F
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
//#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=20;
int n;
string s[N];
int f[1<<N];
vector<int>cnt[N];
int sm[N],mx[N];
signed main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];int mn=0,sum=0;
		cnt[i].resize(s[i].size()*2+10);
		for(int j=0;j<s[i].size();j++){
			if(s[i][j]=='(')sum++;
			else sum--;
			chkmn(mn,sum);
			// -sum
			if(-sum+mn>=0)
				cnt[i][s[i].size()-sum]++;
		}
		sm[i]=sum;mx[i]=mn;
	}
	memset(f,-0x3f,sizeof f);
	f[0]=0;int ans=0;
	for(int S=0;S<(1<<n);S++)for(int i=0;i<n;i++)if(!(S>>i&1)){
		int sum=0;
		for(int j=0;j<n;j++)if(S>>j&1)sum+=sm[j];
		int res=f[S];
		if(sum<=(int)s[i].size()&&sum>=-(int)s[i].size())
		res+=cnt[i][sum+s[i].size()];
		chkmx(ans,res);
		if(sum+mx[i]>=0)
			chkmx(f[S|(1<<i)],res);
	}
	write(ans);
}
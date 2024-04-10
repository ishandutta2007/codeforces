// Problem: CF1582G Kuzya and Homework
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1582G
// Memory Limit: 500 MB
// Time Limit: 2000 ms
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
const int N=1e6+100;
int n,a[N];char c[N];
int pr[N];
vector<int>v[N];stack<int>s;
signed main(){
	for(int i=2;i<N;i++)if(!pr[i])
		for(int j=1;i*j<N;j++)pr[i*j]=i;
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	fgets(c+1,998244353,stdin);
	ll ans=0;
	for(int i=1;i<=n;i++){
		s.push(i);
		while(a[i]>1){
			int j=pr[a[i]];a[i]/=j;
			if(c[i]=='*')v[j].pb(i);
			else{
				while(s.size()&&(!v[j].size()||s.top()>v[j].back()))
					s.pop();
				if(v[j].size())v[j].pop_back();
			}
		}
		ans+=s.size();
	}
	write(ans);
}
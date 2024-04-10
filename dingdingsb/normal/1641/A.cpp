// Problem: A. Great Sequence
// Contest: Codeforces - Codeforces Round #773 (Div. 1)
// URL: https://codeforces.com/contest/1641/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
#define int ll
const int N=2e5+100;
int t,n,x,a[N];
multiset<int>kk;
signed main(){
	read(t);
	while(t--){
		kk.clear();
		read(n,x);
		for(int i=1;i<=n;i++)read(a[i]);
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)
			if(a[i]%x==0&&kk.count(a[i]/x))kk.erase(kk.find(a[i]/x));
			else kk.insert(a[i]);
		write(kk.size());pc('\n');
	}
	
}
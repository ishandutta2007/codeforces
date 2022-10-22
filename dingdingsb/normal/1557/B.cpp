// Problem: B. Moamen and k-subarrays
// Contest: Codeforces - Codeforces Round #737 (Div. 2)
// URL: https://codeforces.com/contest/1557/problem/B
// Memory Limit: 256 MB
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
const int N=1e5+100;
int t,n,k,a[N];vector<int>num;
signed main(){
	read(t);
	while(t--){
		read(n,k);num.clear();
		for(int i=1;i<=n;i++)
			read(a[i]),num.pb(a[i]);
		sort(num.begin(),num.end());
		for(int i=1;i<=n;i++)
			a[i]=lower_bound(num.begin(),num.end(),a[i])-num.begin();
		int res=n;
		for(int i=1;i<n;i++)
			if(a[i]+1==a[i+1])
				res--;
		if(res<=k)puts("Yes");else puts("No");
	}
}
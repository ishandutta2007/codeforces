// Problem: B. Build the Permutation
// Contest: Codeforces - Codeforces Round #758 (Div.1 + Div. 2)
// URL: https://codeforces.com/contest/1608/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const int N=1e5+100;
int t,n,x,y;
int a[N];
signed main(){
	read(t);while(t--){
		read(n,x,y);
		if(abs(x-y)>1||x>(n-1)/2||y>(n-1)/2||x+y>n-2)puts("-1");
		else{
			for(int i=1;i<=n;i++)a[i]=i;
			int l=2,r=n-1;
			if(x<y)swap(a[1],a[2]),y--,l++;
			else if(x>y)swap(a[n],a[n-1]),x--,r--;
			for(int i=1;i<=x;i++){
				swap(a[l],a[l+1]);
				l+=2;
				if(l-1>r)break;
			}
			if(l-1>r)puts("-1");
			else {
				for(int i=1;i<=n;i++)
					write(a[i]),pc(' ');
				pc('\n');
			}
		}
	}
}
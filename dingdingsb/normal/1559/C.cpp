// Problem: C. Mocha and Hiking
// Contest: Codeforces - Codeforces Round #738 (Div. 2)
// URL: https://codeforces.ml/contest/1559/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int t,n,a[N];
signed main(){
	read(t);
	while(t--){
		read(n);int sum1=0;
		for(int i=1;i<=n;i++)
			read(a[i]),sum1+=a[i];
		if(a[n]==0){
			for(int i=1;i<=n+1;i++)
				write(i),putchar(' ');
		}else if(sum1==n){
			write(n+1);putchar(' ');
			for(int i=1;i<=n;i++)
				write(i),putchar(' ');
		}else{
			for(int i=1;i<n;i++)
				if(a[i]==0&&a[i+1]==1){
					for(int j=1;j<=i;j++)
						write(j),putchar(' ');
					write(n+1),putchar(' ');
					for(int j=i+1;j<=n;j++)
						write(j),putchar(' ');
					break;
				}
		}
		putchar('\n');
	}
}
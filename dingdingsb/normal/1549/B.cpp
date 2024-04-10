// Problem: B. Gregor and the Pawn Game
// Contest: Codeforces - Codeforces Round #736 (Div. 2)
// URL: https://codeforces.com/contest/1549/problem/B
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
const int N=2e5+100;
int t,n;char a[N],b[N];int fg[N];
signed main(){
	read(t);
	while(t--){
		read(n);
		scanf("%s",a+1);
		scanf("%s",b+1);
		a[n+1]=b[n+1]=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]=='0'){
				if(b[i]=='1')
					ans++,b[i]=0;
			}else if(a[i]=='1'){
				if(b[i-1]=='1')ans++,b[i-1]=0;
				else if(b[i+1]=='1')ans++,b[i+1]=0;
			}
		}
		write(ans);putchar('\n');
	}
}
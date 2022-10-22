// Problem: CF1558C Bottom-Tier Reversals
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1558C
// Memory Limit: 500 MB
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
const int N=3000;
int t,n,a[N];vector<int>ans;
int find(int x){for(int i=1;;i++)if(a[i]==x)return i;}
void rever(int x){ans.pb(x);reverse(a+1,a+1+x);}
signed main(){
	read(t);while(t--){
		ans.clear();
		read(n);for(int i=1;i<=n;i++)read(a[i]);
		for(int i=1;i<=n;i++)if(abs(a[i]-i)&1){puts("-1");goto loop;}
		for(int i=1;i<=n/2;i++){
			int pos1=find(2*i-1);
			rever(pos1);
			int pos2=find(i*2);
			rever(pos2-1);
			rever(pos2+1);
			rever(3);
			rever(n-2*i+2);
		}
		rever(n);
		write(ans.size());putchar('\n');
		for(auto x:ans)write(x),putchar(' ');
		putchar('\n');
		loop:;
	}
}
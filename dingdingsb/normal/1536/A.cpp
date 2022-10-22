// Problem: CF1536A Omkar and Bad Story
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1536A
// Memory Limit: 250 MB
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
int t,n,a;
signed main(){
	read(t);
	while(t--){
		bool flag=1;
		read(n);
		for(int i=1;i<=n;i++)
			read(a),flag&=a>=0;
		if(flag){
			puts("yEs");
			write(101);putchar('\n');
			for(int i=0;i<=100;i++)write(i),putchar(' ');
			putchar('\n');
		}else puts("No");
	}
	return 0;
	cout<<"c*Fn***";
}
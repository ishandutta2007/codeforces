// Problem: CF1547A Shortest Path with Obstacle
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1547A
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
#define x1 asdjkashjkd
#define y1 skjdkjsfjks
#define x2 sdkfjjksdjf
#define y2 askjhdjksas
#define x3 asdjjksjdjj
#define y3 ijshdjkhhhh
int t,x1,y1,x2,y2,x3,y3;
signed main(){
	read(t);while(t--){
		read(x1,y1,x2,y2,x3,y3);
		if(x1==x2&&x2==x3&&min(y1,y2)<=y3&&y3<=max(y1,y2))write(abs(y2-y1)+2);
		else if(y1==y2&&y2==y3&&min(x1,x2)<=x3&&x3<=max(x1,x2))write(abs(x2-x1)+2);
		else write(abs(x1-x2)+abs(y1-y2));putchar('\n');
	}
}
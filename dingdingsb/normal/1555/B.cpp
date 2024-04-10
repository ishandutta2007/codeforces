// Problem: B. Two Tables
// Contest: Codeforces - Educational Codeforces Round 112 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1555/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include<bits/stdc++.h>
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
#define y1 sdofhjasdfifdghkasg
#define y2 da23sfhkjlslbfjsbks
int t;int W,H,x1,x2,y1,y2,w,h;
int ans;
signed main(){
	read(t);
	while(t--){
		read(W,H,x1,y1,x2,y2,w,h);
		ans=0x3f3f3f3f;
		if(y2-y1+h<=H)
			ans=min(ans,max(0,h-y1)),
			ans=min(ans,max(y2-(H-h),0));
		swap(W,H);swap(x1,y1);swap(x2,y2);swap(w,h);
		if(y2-y1+h<=H)
			ans=min(ans,max(0,h-y1)),
			ans=min(ans,max(y2-(H-h),0));
		if(ans==0x3f3f3f3f)puts("-1");
		else write(ans),putchar('\n');
	}
	return 0;
	cout<<"ccfn***";
}
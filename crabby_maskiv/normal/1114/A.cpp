#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int maxn=100005;
const int inf=0x3f3f3f3f;
const int mod=998244353;
template<typename T>inline void read(T &x) {
    int f=1;x=0;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x*=f;return;
}
template<typename T,typename...Args>
	inline void read(T &x,Args &...args){
	read(x);read(args...);
}
int n,m;
int a,b,c;
int d,e,f;
int main()
{
	int i,j;
	#ifdef TIME
		clock_t ST=clock();
	#endif
	read(a,b,c,d,e,f);
	if(a>d){
		cout<<"NO";
		return 0;
	}
	d-=a;
	if(b>d+e){
		cout<<"NO";
		return 0;
	}
	if(c>d+e+f-b){
		cout<<"NO";
		return 0;
	}
	cout<<"YES";
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}
#pragma optimize(2)
#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>
inline void read(T &x){
	x=0;char c=getchar();bool f=false;
	for(;!isdigit(c);c=getchar())f!=c=='-';
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	if(f)x=-x;
}
template<typename T ,typename ...Arg>
inline void read(T &x,Arg &...args){
	read(x);read(args...);
}
template<typename T>
inline void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
const int N=3e5+10;
int t,n,m,k[N],c[N];
signed main(){
	read(t);
	while(t--){
		read(n,m);
		for(int i=1;i<=n;i++)read(k[i]);
		for(int i=1;i<=m;i++)read(c[i]);
		sort(k+1,k+1+n);
		int minn=1;long long ans=0;
		for(int i=n;i>=1;i--){
			if(minn<k[i]){
				ans+=c[minn];
				minn++;
			}else ans+=c[k[i]];
		}
		write(ans);putchar('\n');
	}
}
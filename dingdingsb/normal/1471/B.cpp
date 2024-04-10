#pragma optimize(2)
#include<bits/stdc++.h>
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
#define int long long
const int N=1e5+10;
int t,n,x,a[N],b[N];
signed main(){
	read(t);
	while(t--){
		read(n,x);
		for(int i=1;i<=n;i++)read(a[i]),b[i]=a[i];
		int sum=0;int now=1;
		for(;;now*=x){
			int tmp=0;
			for(int i=1;i<=n;i++)
				if(a[i]%x){
					sum+=tmp;
					goto loop;
				}else{
					tmp+=b[i];
					a[i]/=x;
				}
			sum+=tmp;
		}
		loop:;
		for(int i=1;i<=n;i++)
			sum+=b[i];
		write(sum);putchar('\n');
	}
	return 0;
	cout<<"AFOAFO";
}
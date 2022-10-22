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
vector<int>p;
void init(int maxn){
	for(int i=2;i<=maxn;i++){
		for(int j=2;j<i;j++)
			if(i%j==0)
				goto loop;
		p.push_back(i);
		loop:;
	}
}
int n,a;
const int maxn_wei=20;
struct node{
	//
	int b[maxn_wei];
	void insert(int x){
		for(int i=maxn_wei-1;i>=0;i--){
			if(!(x&(1<<i)))continue;
			if(!b[i]){
				b[i]=x;
				return ;
			}
			x^=b[i];
		}
	}
}Base;
long long qpow(int x){
	int ret=1,mod=1e9+7,a=2;
	while(x){
		if(x&1)ret=ret*a%mod;
		a=a*a%mod,x>>=1;
	}
	return ret;
}
signed main(){
	read(n);init(70);
	for(int i=1;i<=n;i++){
		read(a);int now=0;
		for(int j=0;j<p.size();j++){
			now<<=1;
			while(a%p[j]==0)
				a/=p[j],now^=1;
		}
		Base.insert(now);
	}
	for(int i=maxn_wei-1;i>=0;i--)
		n-=Base.b[i]!=0;
	cout<<qpow(n)-1; 
}
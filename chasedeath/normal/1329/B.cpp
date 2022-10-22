#include<bits/stdc++.h> 
using namespace std;

#define reg register
typedef long long ll;
typedef unsigned int ui;
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)

#define pb push_back
template <class T> inline void cmin(T &a,T b){ if(a>b) a=b; }
template <class T> inline void cmax(T &a,T b){ if(a<b) a=b; }

char IO;
template <class T=int> T rd(){
	T s=0;
	int f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=200+10,P=998244353;

int n,m;

int main(){
	rep(kase,1,rd()) {
		n=rd()-1,m=rd();
		ll ans=1,d=2;
		int p=1;
		while(n) {
			p<<=1;
			ans+=min(n,p)*d%m;
			n-=min(n,p);
			d=ans+1;
		}
		ans%=m;
		printf("%lld\n",ans);
	}
}
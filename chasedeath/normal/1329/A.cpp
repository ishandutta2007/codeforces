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

const int N=1e5+10,P=998244353;

int n,m;
int a[N];

int main(){
	n=rd(),m=rd();
	ll s=0;
	rep(i,1,m) {
		a[i]=rd();
		s+=a[i];
		if(i+a[i]-1>n) return puts("-1"),0;
	}
	if(s<n) return puts("-1"),0;
	s=n+1;
	drep(i,m,1) {
		s=max((ll)i,s-a[i]);
		a[i]=s;
	}
	rep(i,1,m) printf("%d ",a[i]); puts("");
}
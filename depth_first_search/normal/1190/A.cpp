#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100000
#define LL long long
using namespace std;
int n;LL s,k,a[N+5];
int main()
{
	RI i,j,t=0;for(cin>>s>>n>>k,i=1;i<=n;++i) cin>>a[i];
	for(i=1;i<=n;i=j+1) {for(j=i;j^n&&(a[i]-i)/k==(a[j+1]-i)/k;++j);++t;}
	return cout<<t<<endl,0;
}
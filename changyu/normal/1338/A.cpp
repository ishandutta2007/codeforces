#include<bits/stdc++.h>
const int N=1e5+3;
int n,a[N],mx;
inline int Lg(int a){int s=0;for(;a;a>>=1)++s;return s;}
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	mx=0;
	for(int i=2;i<=n;i++)if(a[i]<a[i-1]){
	  mx=std::max(mx,Lg(a[i-1]-a[i]));
	  a[i]=a[i-1];
	}
	printf("%d\n",mx);
	}return 0;
}
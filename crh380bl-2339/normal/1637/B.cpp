#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<class T>
void read(T &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
int a[105];
int main(){
	int t,n,i;
	ll s;
	read(t);
	while(t--){
		read(n);
		s=0;
		for(i=1;i<=n;++i){
			scanf("%d",&a[i]);
			++a[i];
			if(a[i]==1)a[i]=2;
			else a[i]=1;
			s=s+1LL*a[i]*i*(n-i+1);
		}
		printf("%lld\n",s);
	}
	return 0;
}
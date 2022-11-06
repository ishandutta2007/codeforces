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
int a[5];
int main(){
	int T,i;
	read(T);
	while(T--){
		for(i=1;i<=4;++i)scanf("%d",&a[i]);
		sort(a+1,a+1+4);
		printf("%lld\n",1LL*a[1]*a[3]);
	}
	return 0;
}
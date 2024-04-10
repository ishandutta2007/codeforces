#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define inv3 333333336
#define fo(i,j,k) for(int i=(j),end_i=(k);i<=end_i;i++)
#define fd(i,j,k) for(int i=(j),end_i=(k);i>=end_i;i--)
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
int main(){
	int n,i,s=6;
	read(n);
	for(i=2;i<=n;++i){
		s=1LL*s*s%mod*8%mod*inv3%mod;
	}
	printf("%d\n",s);
	return 0;
}
#include<bits/stdc++.h>
#define ll long long
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
	int T;ll n;
	scanf("%d",&T);
	while(T--){
		read(n);
		printf("%lld %lld\n",-n+1,n);
	} 
	return 0;
}
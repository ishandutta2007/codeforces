#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1000000000;
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
ll gcd(ll x,ll y){
	return !y?x:gcd(y,x%y);
}
ll lcm(ll x,ll y){
	return x/gcd(x,y)*y;
}
int main(){
	int T,n,i;
	ll x,g=1;
	read(T);
	while(T--){
		read(n);
		bool flg=1;g=1;
		for(i=1;i<=n;++i){
			read(x);
			if(g<=N)g=lcm(g,1LL*i+1);
			if(g<=N&&x%g==0){
				flg=0;
			}
		}
		if(flg)puts("YES");
		else puts("NO");
	} 
	return 0;
}
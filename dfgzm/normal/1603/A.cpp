#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=100010;
ll gcd(ll x,ll y){
	return x?gcd(y%x,x):y;
}
ll i,j,k,n,m,T,a[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++)a[i]=read();
		ll s=1;
		bool b=false;
		for(i=1;i<=n;i++){
			if(s<=1000000000)s=s*(i+1)/gcd(s,i+1);
			if(a[i]%s==0)b=true;
		}
		if(b)puts("NO");
		else puts("YES");
	}
	return 0;
}
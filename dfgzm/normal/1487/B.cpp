#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
ll i,j,k,n,m,T;
int main(){
	cin>>T;
	while(T--){
		n=read();k=read();
		if(n&1){
			printf("%lld\n",(k+(k-1)/(n/2)-1)%n+1);
		}else{
			printf("%lld\n",(k-1)%n+1);
		}
	}
	return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int i,j,k,n,m,T;
ll x,y;
int main(){
	cin>>T;
	while(T--){
		ll ans=0;
		x=read();y=read();
		for(i=1;i<=sqrt(x)+1;i++){
			// k=i a=k(b+1)
//			cout<<"... k="<<i<<" ans="<<min(y,x/i-1)-i<<endl;
			ans+=max(0ll,min(y,x/i-1)-i);
		}printf("%lld\n",ans);
	}
	return 0;
}
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
ll a,b;
int main(){
	cin>>T;
	while(T--){
		scanf("%lld%lld",&a,&b);
		ll ans;
		if(b%a==0)ans=a;
		else if(a>b)ans=a+b;
		else{
			a/=2;b/=2;
			ll t=b/a;
			ll s=b-a*t;
//			cout<<"t="<<t<<" s="<<s<<endl;
			ans=a*2*t+s;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
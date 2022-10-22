#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	char c=getchar();ll x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
ll i,j,k,n,m,T,is_prime[200010],prime[200010],cnt,Max1,Max2;
void init(){
	for(i=2;i<=200000;i++)is_prime[i]=1;
	for(i=2;i<=200000;i++)
		if(is_prime[i])prime[++cnt]=i;
		else{
			for(j=1;j<=cnt && i*prime[j]<=200000;j++){
				is_prime[i*prime[j]]=0;
				if(i%prime[j]==0)break;
			}
		}
}
int main(){
	init();
	T=read();
	while(T--){
		n=read();Max1=0;
		for(i=1;i<=cnt && prime[i]*prime[i]<=n;i++){
			ll N=n,ans=0;
			while(N%prime[i]==0)++ans,N/=prime[i];
			if(ans>Max1)Max1=ans,Max2=prime[i];
		}if(!Max1)Max1++;
		printf("%lld\n",Max1);
		for(i=1;i<Max1;i++)printf("%lld ",Max2),n/=Max2;
		printf("%lld\n",n);
	}
	return 0;
}
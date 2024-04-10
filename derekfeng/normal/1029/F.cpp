#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N,p,q;
ll a,b,ans=1e18;
ll fc[1000000];
ll f1[1000000];
ll f2[1000000];
int main(){
	scanf("%I64d%I64d",&a,&b);
	for(ll i=1;i*i<=a+b;i++)if((a+b)%i==0)fc[++N]=(a+b)/i;
	for(ll i=1;i*i<=a;i++)if(a%i==0)f1[++p]=a/i;
	for(ll i=1;i*i<=b;i++)if(b%i==0)f2[++q]=b/i;
	sort(fc+1,fc+N+1);
	sort(f1+1,f1+p+1);
	sort(f2+1,f2+q+1);
	int s=0;
	for(int i=1;i<=p;i++){
		while(fc[s]<f1[i])++s;
		if((a+b)/fc[s]<a/f1[i])continue;
		ans=min(ans,fc[s]+(a+b)/fc[s]);
	}
	s=0;
	for(int i=1;i<=q;i++){
		while(fc[s]<f2[i])++s;
		if((a+b)/fc[s]<b/f2[i])continue;
		ans=min(ans,fc[s]+(a+b)/fc[s]);
	}
	printf("%lld\n",ans*2);
}
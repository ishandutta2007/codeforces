#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=300010;

ll a,b,c,d;
ll ans=0;

int main()
{
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	for(int z=c;z<=d;z++)
	{
		if(z>=c+b) continue;
		if(b+a>z) ans+=(c-b+1)*(b-a+1);
		else 
		{
			ll tmp=z-c+1,num,beg,ed=c;//b-tmp~b
			if(tmp<a) ans+=(a-tmp)*(b-a+1),ed=c-(a-tmp),tmp=a;
			num=min(b-tmp+1,ed-b+1),beg=b-tmp+1;
			ans+=(beg+beg-num+1)*num/2;
		}
	}
		printf("%lld\n",ans);
	return 0;
}
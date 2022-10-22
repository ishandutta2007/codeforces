#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,l;

ll ans=0x3f3f3f3f3f3f3f3f;
ll a[100];
int lbt(int x)
{
	return x&(-x);
}
void check(int key)
{
	int i;ll cnt=0;
	for(i=1;i<=31;i++)
		if(key&(1LL<<i-1))
			cnt+=a[i];
	ans=min(ans,cnt);
}
int main()
{
    cin>>n>>l;
    int i,j;
    memset(a,0x3f,sizeof(a));
    for(i=1;i<=n;i++) cin>>a[i];
	for(i=2;i<=31;i++) 
	{
		if(a[i]>a[i-1]*2) a[i]=a[i-1]*2;
		//cout<<a[i]<<" ";
	}
	while(l<(1LL<<31))
	{
		check(l);
		l+=lbt(l);
	}
	cout<<ans;
    return 0;
}
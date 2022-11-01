#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int maxn=123456;
typedef long long ll;
int mu[maxn],prime[maxn],cnt[maxn],Pow[maxn];
int vis[maxn];
int n;
int total;
void shai()
{
	mu[1] = 1; //
    for (int i = 2; i <= maxn; i++)
	{
        if (!vis[i])  //
		{
            prime[++total] = i; //
            mu[i] = -1;  //
        }
        for (int j = 1; j <= total; j++)//
		{ 
            if (i * prime[j] > maxn) break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) 
			{
                mu[prime[j] * i] = 0;
                break;
            }
            mu[prime[j] * i]  = - mu[i];
            //i6
            //2,3,56212break
            //1899*2=18
        }
    }
}
int main()
{
	ll ans = 0 ;
	int x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		for(int j=1;j*j<=x;j++)
		{
			if(x%j==0){
				cnt[j]++;
			    if(j!=x/j)
			    {
			 		cnt[x/j]++;   	
				}
			}
		}
	}
	Pow[0]=1;
	for(int i=1;i<maxn;i++)
	{
		Pow[i]=(Pow[i-1]*2)%mod;
	}
	shai();
	for(int i=1;i<maxn;i++)
	{
		ans = (ans + (Pow[cnt[i]]-1)*mu[i])%mod;
	}
	ans=(ans+mod)%mod;
	cout<<ans<<endl;
	return 0;
}
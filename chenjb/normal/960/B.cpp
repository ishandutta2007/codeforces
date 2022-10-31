#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
using namespace std;
int n,k1,k2;
int a[2000010],b[2000010];
int main()
{
	cin>>n>>k1>>k2;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	int k = k1 + k2;
	while(k1+k2!=0)
	{
	    int maxp=0;
	    int maxx=-1;
        for(int i=1;i<=n;i++)
            if(abs(a[i]-b[i])>maxx){ maxx=abs(a[i] - b[i]); maxp=i; }

        if (a[maxp]<=b[maxp])
        {
            if(k1>0){ k1--; a[maxp]++; }
            else { k2--; b[maxp]--; }
        }

        else if(a[maxp]>b[maxp])
        {
            if(k1>0){ k1--; a[maxp]--; }
            else { k2--; b[maxp]++; }
         }
	}
	long long ans=0;
	for(int i=1;i<=n;i++)ans=ans+1ll*(a[i] - b[i]) * (a[i] - b[i]);
    cout<<ans<<endl;
	return 0;
}
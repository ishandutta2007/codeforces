#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,k;
    cin >> a >> b >> k;
    vector<bool> sieve(b+1,1);
    sieve[1]=0;
    for(ll i=2;i<=b;i++)
    {
        if(sieve[i]==0) continue;
        for(ll j=i*i;j<=b;j+=i) sieve[j]=0;
    }
    vector<int> sum(b+1,0);
    for(int i=1;i<=b;i++) sum[i]=sum[i-1]+sieve[i];
    auto s=[&](int c,int d)->int{return sum[d]-sum[c-1];};
    int l=0,r=b-a+2;
    while(l<r-1)
    {
        int m=(l+r)/2;
        bool ok=1;
        for(int i=a;i+m-1<=b;i++) ok&=(s(i,i+m-1)>=k);
        if(ok) r=m;
        else l=m;
    }
    if(r==b-a+2) r=-1;
    cout << r << "\n";
    return 0;
}
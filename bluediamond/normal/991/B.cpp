#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n,v[105];

int gt()
{
    double sum=0;
    for(int i=1;i<=n;i++)
        sum+=v[i];
    double x=n;
    double val=sum/x;
    int ad=val;
    double aux=ad;
    if(val-aux>=0.5)
        return ad+1;
    return ad;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    sort(v+1,v+n+1);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(gt()==5)
        {
            cout<<ans<<"\n";
            return 0;
        }
        ans++;
        v[i]=5;
    }
    cout<<ans<<"\n";
    return 0;
}
/**

3
4 5 5


**/
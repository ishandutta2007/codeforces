#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=500+5;
int n,v[N];
int w=1;
ll cnt=0,mom=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>cnt;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    for(int j=2;j<=n;j++)
    {
        if(v[j]>v[w])
        {
            w=j;
            mom=0;
        }
        mom++;
        if(mom==cnt)
        {
            cout<<v[w]<<"\n";
            return 0;
        }
    }
    cout<<n<<"\n";
    return 0;
}
/**
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=(int)1e5+5;
int n;
ll v[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    v[0]=-(1LL<<60);
    v[n+1]=(1LL<<60);
    for(int i=1;i<=n;i++)
    {
        cout<<min(v[i]-v[i-1],v[i+1]-v[i])<<" "<<max(v[i]-v[1],v[n]-v[i])<<"\n";
    }
    return 0;
}
/**

**/
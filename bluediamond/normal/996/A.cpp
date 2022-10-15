#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n;
int v[]={1, 5, 10, 20, 100};/// 0 1 2 3 4

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int ans=0;
    for(int i=4;i>=0;i--)
    {
        int cnt=n/v[i];
        ans+=cnt;
        n%=v[i];
    }
    cout<<ans<<"\n";
    return 0;
}
/**

**/
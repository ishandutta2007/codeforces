#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100000+5;

int n;
int need,mi=(1<<30);
ll co=0LL;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>need>>x;
        mi=min(mi,x);
        co+=mi*(long long)need;
    }
    cout<<co<<"\n";
    return 0;
}
/**


**/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=100000;

int n;
ll poz;

ll x[N+5],y[N+5];

ll a,b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>poz;
    cin>>a>>b;
    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i];
    poz%=(2*n);
    for(int i=1;i<=poz;i++)
    {
        a=2*x[(i-1+n)%n]-a;
        b=2*y[(i-1+n)%n]-b;
    }
    cout<<a<<" "<<b<<"\n";
    return 0;
}
/**


3 2143
0 0
1 1
2 3
-5 3


**/
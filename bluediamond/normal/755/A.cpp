#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

bool isp(int x)
{
    if(x<=1)
        return 0;
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=i;i++)
        if(isp(i*n+1)==0)
            cout<<i<<"\n", exit(0);
    return 0;
}
/**



**/
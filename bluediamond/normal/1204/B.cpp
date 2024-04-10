#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n;
int l,r;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        cin>>n>>l>>r;
        cout<<(1<<l)-1+n-l<<" "<<(1<<r)-1+(n-r)*(1<<(r-1));

        return 0;
}
/**

**/
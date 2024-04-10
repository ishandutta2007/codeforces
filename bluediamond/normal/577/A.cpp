#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n,x;
int res=0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>x;
    for(int r=1;r<=n;r++)
    {
        if(x%r==0)
        {
            int c=x/r;
            if(c<=n)
            {
                res++;
            }
        }
    }
    cout<<res<<"\n";
    return 0;
}
/**


**/
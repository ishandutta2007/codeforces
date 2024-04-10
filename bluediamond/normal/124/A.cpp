#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,a,b;
    cin>>n>>a>>b;
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int x=i-1;
        int y=n-i;
        if(x>=a && y<=b)
        {
            res++;
        }
    }
    cout<<res<<"\n";
    return 0;
}
/**


**/
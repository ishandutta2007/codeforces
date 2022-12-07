#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    long long su=0;
    for(int a=0; a<m; a++)
    {
        int x, d;
        scanf("%d%d", &x, &d);
        su+=x*n;
        if(d>=0) su+=((1ll*(n-1)*n)/2)*d;
        else
        {
            int p=n/2;
            su+=((1ll*p*(p+1))/2)*d;
            su+=((1ll*(n-p-1)*(n-p))/2)*d;
        }
    }
    cout<<fixed<<setprecision(10)<<(su*1.0)/n;
}
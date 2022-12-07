#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, p;
    cin>>n>>p;
    int ar[n][2];
    for(int a=0; a<n; a++) cin>>ar[a][0]>>ar[a][1];
    double l=0, r=9e18, eps=1e17;
    for(int a=0; a<150; a++)
    {
        double mid=(l+r)/2, su=0;
        for(int a=0; a<n; a++)
        {
            double za=ar[a][0]*mid;
            if(za>ar[a][1]) su+=(za-ar[a][1])/p;
        }
        if(su>mid) r=mid;
        else l=mid;
    }
    if(abs(r-9e18)<eps) cout<<-1;
    else cout<<fixed<<r;
}
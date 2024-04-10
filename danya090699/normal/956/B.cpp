#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, u;
    cin>>n>>u;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    int yk=0;
    double an=-1e9;
    for(int a=0; a<n; a++)
    {
        while(yk<n)
        {
            if(ar[yk]<=ar[a]+u) yk++;
            else break;
        }
        if(yk>a+2) an=max(an, (1.0*(ar[yk-1]-ar[a+1]))/(ar[yk-1]-ar[a]));
    }
    if(an<0) cout<<-1;
    else cout<<fixed<<setprecision(10)<<an;
}
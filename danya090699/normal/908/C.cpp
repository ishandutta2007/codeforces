#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, r;
    cin>>n>>r;
    int ar[n];
    double an[n];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        an[a]=r;
        for(int b=0; b<a; b++)
        {
            int di=abs(ar[a]-ar[b]);
            if(di<=2*r)
            {
                an[a]=max(an[a], an[b]+sqrt(4*r*r-di*di));
            }
        }
        cout<<fixed<<setprecision(10)<<an[a]<<" ";
    }
}
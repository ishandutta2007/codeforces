#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, mi=2e9;
    cin>>n;
    int ar[n], pr=-1e9, an=2e9;
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        mi=min(mi, ar[a]);
    }
    for(int a=0; a<n; a++)
    {
        if(ar[a]==mi)
        {
            an=min(an, a-pr), pr=a;
        }
    }
    cout<<an;
}
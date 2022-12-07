#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    for(int a=0; a<t; a++)
    {
        int pr=0, k, n, an=0;
        cin>>n>>k;
        int ar[k];
        for(int a=0; a<k; a++)
        {
            cin>>ar[a];
            if(a>0) an=max(an, (ar[a]-ar[a-1])/2+1);
        }
        an=max(an, max(ar[0], n-ar[k-1]+1));
        cout<<an<<"\n";
    }
}
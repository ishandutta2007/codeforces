#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    if(n==1) cout<<ar[0];
    else if(n==2) cout<<(ar[0]|ar[1]);
    else
    {
        int an=0;
        for(int a=0; a<n; a++)
        {
            for(int b=a+1; b<n; b++)
            {
                int x=ar[a]|ar[b];
                for(int c=b+1; c<n; c++) an=max(an, x|ar[c]);
            }
        }
        cout<<an;
    }
}
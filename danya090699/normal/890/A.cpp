#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n=6, su=0, ok=0;
    int ar[n];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        su+=ar[a];
    }
    for(int a=0; a<n; a++)
    {
        for(int b=a+1; b<n; b++)
        {
            for(int c=b+1; c<n; c++) if((ar[a]+ar[c]+ar[b])==(su-ar[a]-ar[b]-ar[c])) ok=1;
        }
    }
    if(ok) cout<<"YES";
    else cout<<"NO";
}
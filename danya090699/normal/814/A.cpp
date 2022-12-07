#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    if(k==1)
    {
        int ar[n], x, pos=1;
        for(int a=0; a<n; a++) cin>>ar[a];
        cin>>x;
        for(int a=0; a<n-1; a++)
        {
            if(ar[a]==0) ar[a]=x;
            if(ar[a+1]==0) ar[a+1]=x;
            if(ar[a]>=ar[a+1]) pos=0;
        }
        if(pos) cout<<"No";
        else cout<<"Yes";
    }
    else cout<<"Yes";
}
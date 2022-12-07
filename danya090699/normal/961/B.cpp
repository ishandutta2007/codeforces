#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, an=0;
    cin>>n>>k;
    int ar[n], s[n], cu=0, yk=0;
    for(int a=0; a<n; a++) cin>>ar[a];
    for(int a=0; a<n; a++) cin>>s[a];
    for(int a=0; a<n; a++) if(s[a]) cu+=ar[a];
    for(int a=0; a+k<=n; a++)
    {
        while(yk<a+k)
        {
            if(s[yk]==0) cu+=ar[yk];
            yk++;
        }
        an=max(an, cu);
        if(s[a]==0) cu-=ar[a];
    }
    cout<<an;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    cin>>n;
    int ar[n], pref[n+1][2], suf[n+1][2];
    pref[0][0]=0, pref[0][1]=0;
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        ar[a]--;
        pref[a+1][0]=pref[a][0];
        pref[a+1][1]=pref[a][1];
        pref[a+1][ar[a]]++;
    }
    suf[n][0]=0, suf[n][1]=0;
    for(int a=n-1; a>=0; a--)
    {
        suf[a][0]=suf[a+1][0];
        suf[a][1]=suf[a+1][1];
        suf[a][ar[a]]++;
    }
    for(int a=0; a<=n; a++)
    {
        int ma=0;
        for(int b=a; b<=n; b++)
        {
            ma=max(ma, pref[b][1]+suf[b][0]);
            an=max(an, ma-pref[a][1]-suf[b][0]+pref[a][0]+suf[b][1]);
        }
    }
    cout<<an;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q, an=0;
    cin>>n>>q;
    int ar[q][2];
    for(int a=0; a<q; a++)
    {
        cin>>ar[a][0]>>ar[a][1];
        ar[a][0]--;
    }
    for(int a=0; a<q; a++)
    {
        int pref[n+1], add[n+1];
        for(int b=0; b<=n; b++) add[b]=0;
        for(int b=0; b<q; b++)
        {
            if(b!=a) add[ar[b][0]]++, add[ar[b][1]]--;
        }
        int cu=0, su=0;
        pref[0]=0;
        for(int b=0; b<n; b++)
        {
            cu+=add[b];
            pref[b+1]=pref[b];
            if(cu==1) pref[b+1]++;
            if(cu>0) su++;
        }
        for(int b=a+1; b<q; b++)
        {
            int l=ar[b][0], r=ar[b][1];
            an=max(an, su-(pref[r]-pref[l]));
        }
    }
    cout<<an;
}
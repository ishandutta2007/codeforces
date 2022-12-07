#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar1[n], ar2[n];
    for(int a=0; a<n; a++) cin>>ar1[a];
    for(int a=0; a<n; a++) cin>>ar2[a];
    for(int a=0; a<n; a++)
    {
        int us[n], pos=1;
        for(int b=0; b<n; b++) us[b]=0;
        for(int b=0; b<n; b++)
        {
            if(b!=a)
            {
                if(us[ar1[b]-1]==0) us[ar1[b]-1]=1;
                else pos=0;
            }
        }
        if(pos)
        {
            int x, an[n], q=0;
            for(int b=0; b<n; b++) if(us[b]==0) x=b+1;
            for(int b=0; b<n; b++)
            {
                if(a==b) an[b]=x;
                else an[b]=ar1[b];
            }
            for(int b=0; b<n; b++) if(an[b]!=ar2[b]) q++;
            if(q==1)
            {
                for(int b=0; b<n; b++) cout<<an[b]<<" ";
                break;
            }
        }
    }
}
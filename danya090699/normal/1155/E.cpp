#include <bits/stdc++.h>
using namespace std;
const int mod=1e6+3, sz=11;
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=(1ll*re*x)%mod;
        y>>=1;
        x=(1ll*x*x)%mod;
    }
    return re;
}
int de(int x, int y){return (1ll*x*po(y, mod-2))%mod;}
int ma[sz][sz+1];
int main()
{
    for(int a=1; a<=sz; a++)
    {
        int cu[sz+1], fo=0;
        for(int b=0; b<sz; b++) cu[b]=po(a, b);
        cout<<"? "<<a<<"\n";
        cin>>cu[sz];
        for(int b=sz-1; b>=0; b--)
        {
            if(cu[b])
            {
                if(ma[b][b])
                {
                    int d=de(cu[b], ma[b][b]);
                    for(int c=0; c<=sz; c++)
                    {
                        cu[c]-=(1ll*ma[b][c]*d)%mod;
                        if(cu[c]<0) cu[c]+=mod;
                    }
                }
                else
                {
                    for(int c=0; c<=sz; c++) ma[b][c]=cu[c];
                    break;
                }
            }
        }
    }

    int va[sz];
    for(int a=0; a<sz; a++)
    {
        va[a]=de(ma[a][sz], ma[a][a]);
        for(int b=0; b<sz; b++)
        {
            ma[b][sz]-=(1ll*va[a]*ma[b][a])%mod;
            if(ma[b][sz]<0) ma[b][sz]+=mod;
        }
    }
    bool fo=0;
    for(int a=0; a<mod; a++)
    {
        int su=0;
        for(int b=0; b<sz; b++) su=(su+1ll*va[b]*po(a, b))%mod;
        if(su==0)
        {
            fo=1;
            cout<<"! "<<a<<"\n";
            break;
        }
    }
    if(fo==0) cout<<"! -1\n";
}
#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10, mod=1e9+7;
int st2[sz];
int po(int x, int y)
{
    if(y==0) return 1;
    else
    {
        if(y%2) return (1ll*x*po(x, y-1))%mod;
        else
        {
            int x2=po(x, y/2);
            return (1ll*x2*x2)%mod;
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin>>q;
    st2[0]=1;
    for(int a=1; a<sz; a++) st2[a]=(st2[a-1]*2)%mod;
    for(int i=0; i<q; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        vector <int> dq;
        for(int b=2; b*b<=x; b++)
        {
            if(x%b==0)
            {
                dq.push_back(0);
                while(x%b==0)
                {
                    x/=b, dq.back()++;
                }
            }
        }
        if(x>1) dq.push_back(1);
        int an=1;
        for(int a=0; a<dq.size(); a++)
        {
            int ch=1, zn=1;
            for(int b=0; b<dq[a]; b++)
            {
                ch=(1ll*ch*(dq[a]+y-1-b))%mod;
                zn=(1ll*zn*(b+1))%mod;
            }
            an=(1ll*an*ch)%mod;
            an=(1ll*an*po(zn, mod-2))%mod;
        }
        an=(1ll*an*st2[y-1])%mod;
        printf("%d\n", an);
    }
}
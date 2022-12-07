#include <bits/stdc++.h>
using namespace std;
const int sz=1e7+10;
bitset <sz> pri;
int ef[sz], prq[sz], pref[sz], mi[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    pref[1]=0;
    for(int a=2; a<=n; a++)
    {
        ef[a]=1, pri[a]=1, mi[a]=-1;
    }
    for(int a=2; a<=n; a++)
    {
        if(pri[a])
        {
            ef[a]=a-1;
            for(int b=a+a; b<=n; b+=a)
            {
                pri[b]=0, prq[b]++;
                if(mi[b]==-1) mi[b]=a;
                int x=b, q=1;
                while(x%a==0)
                {
                    x/=a, q*=a;
                }
                ef[b]*=q-q/a;
            }
        }
        pref[a]=pref[a-1]+pri[a];
    }
    long long an=0, an2=0;
    for(int a=2; a<=n; a++)
    {
        if(pri[a])
        {
            int x=n/a;
            if(x>1)
            {
                an2+=pref[x]*2;
                an2+=(pref[n/2]-pref[x])*3;
                if(a<=x) an2-=2;
                else an2-=3;
            }
        }
        else
        {
            int s=a-2-pref[a-1], s2=a-ef[a]-1-prq[a];
            an+=(s-s2)*2+s2;
            int x=n/mi[a];
            an+=(pref[x]-prq[a])*2;
            an+=prq[a];
            an+=(pref[n/2]-pref[x])*3;
        }
    }
    cout<<an+an2/2;
}
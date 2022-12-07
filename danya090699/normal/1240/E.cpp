#include <bits/stdc++.h>
using namespace std;
const int sz=5e5+10;
int pref[sz*2], ma[sz*2][2];
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        pref[x]++;
    }
    for(int a=1; a<sz*2; a++)
    {
        if(pref[a]==0) ma[a][0]=ma[a-1][0], ma[a][1]=ma[a-1][1];
        else if(pref[a]==1) ma[a][0]=a, ma[a][1]=ma[a-1][0];
        else ma[a][0]=a, ma[a][1]=a;
        pref[a]+=pref[a-1];
    }
    long long an=0;
    for(int y=2; y<sz; y++)
    {
        int ma1=-1, ma2=-1;
        long long su=0;
        for(int k=sz/y; k>0; k--) su+=(1ll*k*(pref[(k+1)*y-1]-pref[k*y-1]));
        for(int k=sz/y; k>=0; k--)
        {
            int cu1=ma[(k+1)*y-1][0]-k*y, cu2=ma[(k+1)*y-1][1]-k*y;

            if(ma1<cu1) ma1=cu1;
            else if(ma2<cu1) ma2=cu1;
            ma2=max(ma2, cu2);
            if(ma2>=0)
            {
                int x=min(1ll*(ma2+k*y), su-2*k);
                if(x>1) an=max(an, 1ll*x*y);
            }
            if(ma1>=0)
            {
                int x=min(1ll*(ma1+k*y)/2, su-k);
                if(x>1) an=max(an, 1ll*x*y);

                int qq=pref[sz];
                if(k*y+ma1) qq-=pref[k*y+ma1-1];

                if(qq>1)
                {
                    int x=min(1ll*(ma1+k*y), su-2*k-1);
                    if(x>1) an=max(an, 1ll*x*y);
                }
            }
        }
    }
    cout<<an;
}
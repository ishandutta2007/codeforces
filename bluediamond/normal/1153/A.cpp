#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n;
int t;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>t;
        int minwait=(1<<30),j;
        for(int i=1;i<=n;i++)
        {
                int st,per;
                cin>>st>>per;
                int wait;
                if(t<st)
                {
                        wait=st-t;
                }
                else
                {
                        int dif=t-st;
                        if(dif%per==0)
                        {
                                wait=0;
                        }
                        else
                        {
                                wait=per-dif%per;
                        }
                }
                minwait=min(minwait,wait);
                if(minwait==wait)
                {
                        j=i;
                }
        }
        //cout<<minwait<<"\n";
        cout<<j<<"\n";
        return 0;
}
/**

**/
#include <bits/stdc++.h>

using namespace std;

const int nmax=100;

int n,v[nmax+5];
bool last_sport,last_info,last_liber=1;
int ans=0;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
    {
        if(v[i]==0)
        {
            last_liber=1;
            ans++;
            continue;
        }
        if(v[i]==1)
        {
            if(last_liber==1)
            {
                last_info=1;
                last_sport=0;
                last_liber=0;
                continue;
            }

            if(last_info==1 and last_sport==1)
            {
                last_info=1;
                last_sport=0;
                continue;
            }
            if(last_sport==1)
            {
                last_info=1;
                last_sport=0;
                continue;
            }
            if(last_info==1)
            {
                ans++;
                last_liber=1;
            }
        }
        if(v[i]==2)
        {
            if(last_liber==1)
            {
                last_info=0;
                last_sport=1;
                last_liber=0;
                continue;
            }
            if(last_info==1 and last_sport==1)
            {
                last_info=0;
                last_sport=1;
                continue;
            }
            if(last_info==1)
            {
                last_info=0;
                last_sport=1;
                continue;
            }
            if(last_sport==1)
            {
                ans++;
                last_liber=1;
            }
        }
        if(v[i]==3)
        {
            if(last_liber==1)
            {
                last_info=1;
                last_sport=1;
                continue;
            }
            if(last_info==1 and last_sport==1)
            {
                last_info=1;
                last_sport=1;
                continue;
            }
            if(last_info==1)
            {
                last_info=0;
                last_sport=1;
                continue;
            }
            if(last_sport==1)
            {
                last_info=1;
                last_sport=0;
                continue;
            }
        }
    }
    cout<<ans;
    return 0;
}
/**


    ai equals 0, if on the i-th day of vacations the gym is closed and the contest is not carried out;
    ai equals 1, if on the i-th day of vacations the gym is closed, but the contest is carried out;
    ai equals 2, if on the i-th day of vacations the gym is open and the contest is not carried out;
    ai equals 3, if on the i-th day of vacations the gym is open and the contest is carried out.
**/
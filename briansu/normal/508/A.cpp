#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
const double EPS=1e-4;
const ll INF=ll(1e18);
const int sINF=int(1e8);
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef map<int,int>::iterator mpit;
typedef long long ll;
using namespace std;

bool d[1002][1002];
int cnt[1002][1002];

int main()
{
    int r,c,k;
    cin>>r>>c>>k;
    memset(d,0,sizeof d);
    memset(cnt,0,sizeof cnt);
    for(int i=0;i<k;i++)
    {
        int x,y;
        cin>>x>>y;
        if(!d[x][y])
        {
            d[x][y]=1;
            int mx[]={0,0,1,1},my[]={0,1,0,1};
            for(int j=0;j<4;j++)
            {

                if(++cnt[x+mx[j]][y+my[j]]>=4)
                {
                    cout<<i+1<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<0<<endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
const double EPS=(1e-6);
const ll INF=ll(1e18);
const int sINF=int(1e8);
typedef pair<ll,ll> ii;
typedef pair<ii,int> iii;
typedef map<int,int>::iterator mpit;
typedef long long ll;
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int r,c;
    cin>>r>>c;
    bool d[r][c];
    bool ans[r][c][4];//URDL
    memset(ans,0,sizeof ans);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>d[i][j];
        }
    }
    ll tt=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(d[i][j])continue;
            if(i==0)ans[i][j][0]=0;
            else
            {
                if(d[i-1][j])ans[i][j][0]=1;
                else ans[i][j][0]=ans[i-1][j][0];
            }
            if(j==0)ans[i][j][3]=0;
            else
            {
                if(d[i][j-1])ans[i][j][3]=1;
                else ans[i][j][3]=ans[i][j-1][3];
            }
        }
    }
    for(int i=r-1;i>=0;i--)
    {
        for(int j=c-1;j>=0;j--)
        {
            if(d[i][j])continue;
            if(i==r-1)ans[i][j][2]=0;
            else
            {
                if(d[i+1][j])ans[i][j][2]=1;
                else ans[i][j][2]=ans[i+1][j][2];
            }
            if(j==c-1)ans[i][j][1]=0;
            else
            {
                if(d[i][j+1])ans[i][j][1]=1;
                else ans[i][j][1]=ans[i][j+1][1];
            }
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            for(int k=0;k<4;k++)
            {
                tt+=ans[i][j][k];
            }
        }
    }
    cout<<tt<<endl;
}
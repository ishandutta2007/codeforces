#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<double,int> pdi;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pii;
#define MAXN 100005

vector<int> xy[2][2*MAXN];
int a[MAXN],res[MAXN][2],n,m;

ll prox(int x,int y,int f)
{
    int v=x-y+MAXN;
    if(f)
        v=x+y;

    int p=lower_bound(xy[f][v].begin(),xy[f][v].end(),y-1)-xy[f][v].begin();
    if(p==xy[f][v].size())
    {
        if(!f)
        {
            int xxx=x+(m-y)+1;
            return -min(xxx,n);
        }
        int xxx=x-(m-y)-1;
        return -max(1,xxx);
    }
    return xy[f][v][p];
}

ll solve(int i,int f)
{
    int x=a[i]-1;
    if(f)
        x+=2;
    int p=prox(x,i+1,f);
    if(p<0)
        return -p;
    return res[p][f];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    if(n==1)
    {
        db(0)
        return 0;
    }
    for(int i=0;i<m;i++)
    {
        cin >> a[i];
        xy[0][a[i]-(i+1)+MAXN].push_back(i);
        xy[1][a[i]+i+1].push_back(i);
    }

//    for(int i=0;i<2;i++)
//        for(int j=0;j<2*MAXN;j++)
//            sort(xy[i][j].begin(),xy[i][j].end());

    for(int i=m-1;i>=0;i--)
    {
        res[i][0]=solve(i,0);
        res[i][1]=solve(i,1);
//        cout << res[i][0] << ' ' << res[i][1] << '\n';
    }

    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        ll x1=prox(i,0,0);
        ll x2=prox(i,0,1);
//        cout << x1 << ' ' << x2 << '\n';
//        cout << res[1][0] << ' ' << res[1][1] << '\n';
        if(x1<0)
            x1=-x1;
        else
            x1=res[x1][0];
        if(x2<0)
            x2=-x2;
        else
            x2=res[x2][1];
//        cout << x1 << ' ' << x2 << '\n';
//        db("")
        sum=(sum+(x1-x2+1));
    }
    db(sum)

    return 0;
}
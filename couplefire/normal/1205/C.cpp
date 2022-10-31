#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int n;
int dax[59][59];
int day[59][59];
int dap[59][59];
int ans[59][59];
vector<pii> ngh[59][59];
vector<int> np[59][59];
bool was[59][59];

void dfs(int x, int y)
{
    was[x][y]=true;
    for(int i=0; i<ngh[x][y].size(); i++)
    {
        int kx=ngh[x][y][i].F;
        int ky=ngh[x][y][i].S;
        int pali=np[x][y][i];
        if(!was[kx][ky])
        {
            ans[kx][ky]=1-(pali^ans[x][y]);
            dfs(kx, ky);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    ans[1][1]=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i>1 || j>1) ans[i][j]=-1;
            if(j>=3)
            {
                dax[i][j]=i;
                day[i][j]=j-2;
            }
            else if(i>=2 && j>=2)
            {
                dax[i][j]=i-1;
                day[i][j]=j-1;
            }
            else if(i>=3)
            {
                dax[i][j]=i-2;
                day[i][j]=j;
            }
            if(dax[i][j]>0)
            {
                cout<<"? "<<dax[i][j]<<" "<<day[i][j]<<" "<<i<<" "<<j<<endl;
                fflush(stdout);
                cin>>dap[i][j];
                if((i+j)%2==0)
                {
                    ans[i][j]=1-(dap[i][j]^ans[dax[i][j]][day[i][j]]);
                }
                else
                {
                    ngh[i][j].push_back({dax[i][j], day[i][j]});
                    np[i][j].push_back(dap[i][j]);
                    ngh[dax[i][j]][day[i][j]].push_back({i, j});
                    np[dax[i][j]][day[i][j]].push_back(dap[i][j]);
                }
            }
        }
    }
    int ex=3;
    int ey=1;
    int fx;
    int fy;
    while(1)
    {
        int nx=ex;
        int ny=ey;
        if(nx<n) nx++;
        else ny++;
        if(dap[ex][ey]==dap[nx][ny])
        {
            cout<<"? "<<dax[ex][ey]<<" "<<day[ex][ey]<<" "<<nx<<" "<<ny<<endl;
            fflush(stdout);
            int pali;
            cin>>pali;
            if(ans[ex][ey]<0) ans[ex][ey]=1-(pali^ans[dax[nx][ny]][day[nx][ny]]);
            if(ans[nx][ny]<0) ans[nx][ny]=1-(pali^ans[dax[ex][ey]][day[ex][ey]]);
            if(ans[dax[ex][ey]][day[ex][ey]]<0) ans[dax[ex][ey]][day[ex][ey]]=1-(pali^ans[nx][ny]);
            if(ans[dax[nx][ny]][day[nx][ny]]<0) ans[dax[nx][ny]][day[nx][ny]]=1-(pali^ans[ex][ey]);
            if((ex+ey)%2==1)
            {
                fx=dax[ex][ey];
                fy=day[ex][ey];
            }
            else
            {
                fx=dax[nx][ny];
                fy=day[nx][ny];
            }
            break;
        }
        ex=nx;
        ey=ny;
    }
    cout<<"? "<<1<<" "<<2<<" "<<2<<" "<<3<<endl;
    fflush(stdout);
    int firstpair;
    cin>>firstpair;
    ngh[1][2].push_back({2, 3});
    np[1][2].push_back(firstpair);
    ngh[2][3].push_back({1, 2});
    np[2][3].push_back(firstpair);
    dfs(fx, fy);
    cout<<"!"<<endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    fflush(stdout);
    return 0;
}
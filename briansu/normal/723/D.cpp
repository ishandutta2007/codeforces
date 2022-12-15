#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
const double EPS=1e-8;
const ll INF=ll(1e18);
const int sINF=int(1e8);
typedef pair<int,int> ii;
struct slake
{
    int i;
    int s;
    slake(int i,int s){this->i=i;this->s=s;}
    bool operator < (const slake &b)
    const{
        return this->s<b.s;
    }
};
vector<int> lsize;
vector<vector<ii> >block;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int mcnt=0;
    lsize.push_back(0);
    block.resize(1);
    int lcnt=0,rlcnt=0;
    int a[n+2][m+2];
    for(int i=0;i<=n+1;i++)a[i][0]=a[i][m+1]=-1;
    for(int i=0;i<=m+1;i++)a[0][i]=a[n+1][i]=-1;
    bool v[n+1][m+1];
    memset(v,0,sizeof(v));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char tmp;
            cin>>tmp;
            if(tmp=='*')a[i][j]=0;
            else a[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(!v[i][j]&&a[i][j]==1)
            {
                lcnt++;
                lsize.push_back(1);
                block.resize(lcnt+1);
                block[lcnt].push_back(ii(i,j));//make
                queue<ii> q;
                q.push(ii(i,j));//startBFS
                bool edge=false;
                v[i][j]=true;
                while(!q.empty())
                {
                    ii tmp=q.front();
                    int x=tmp.first,y=tmp.second;//getnow

                    int f[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

                    for(int k1=0;k1<=3;k1++)
                    {
                        int dx=f[k1][0]+x,dy=f[k1][1]+y;
                        if(a[dx][dy]==-1)
                        {
                            edge=true;
                        }
                        else if(a[dx][dy]==1&&!v[dx][dy])
                        {
                            v[dx][dy]=true;
                            lsize[lcnt]++;
                            q.push(ii(dx,dy));
                            block[lcnt].push_back(ii(dx,dy));
                            //cout<<dx<<" "<<dy<<" "<<lcnt<<endl;
                            //tmcnt++;
                        }
                    }
                    q.pop();
                }
                if(edge)
                {
                    lsize[lcnt]=sINF;
                }
                else
                {
                    rlcnt++;
                    //mcnt+=tmcnt;
                }
            }
        }
    }
    vector<slake> fs;
    for(int i=1;i<lsize.size();i++)
    {
        fs.push_back(slake(i,lsize[i]));
    }
    sort(fs.begin(),fs.end());
    for(int i=0;i<rlcnt-k;i++)
    {
        int tmp=fs[i].i;
        for(int j=0;j<block[tmp].size();j++)
        {
            a[block[tmp][j].first][block[tmp][j].second]=0;
            mcnt++;
        }
    }
    cout<<mcnt<<endl;
    //cout<<lcnt<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==0)
            {
                cout<<"*";
            }
            else
            {
                cout<<".";
            }
        }
        cout<<endl;
    }
}
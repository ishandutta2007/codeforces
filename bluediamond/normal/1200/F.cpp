#include <bits/stdc++.h>

using namespace std;

const int nax=1000+7;
const int num=2520;

int rep(int x)
{
        x%=num;
        if(x<0)
                x+=num;
        return x;
}

int geth(int i,int j)
{
        return (i-1)*num+j;
}

int geti(int h)
{
        return h/num+1;
}

int n,q;
int k[nax];
int m[nax];
int e[nax][10];
int point[nax*num];
int len[nax*num];
bool vis[nax*num];
bool act[nax*num];
bool intr[nax*num];
vector <int> path;


void DFS(int x)
{
        path.clear();
        int value;
        while(1)
        {
                path.push_back(x);
                vis[x]=act[x]=1;
                int y=point[x];
                if(act[y])
                {
                        int posy=(int)path.size()-1;
                        while(path[posy]!=y)
                                posy--;
                        set <int> all_nodes;
                        for(int j=posy;j<(int)path.size();j++)
                                all_nodes.insert(geti(path[j]));
                        value=(int)all_nodes.size();
                        break;
                }
                if(vis[y])
                {
                        value=len[y];
                        break;
                }
                x=y;
        }

        for(auto &it : path)
                act[it]=0;
        for(auto &it : path)
                len[it]=value;


}

void pok(bool e)
{
        if(!e)
        {
                cout<<"Oooooooops\n";
        }
}

int main()
{
        bool home=0;
        if(home)
        {
                freopen("__input__","r",stdin);
        }
        else
        {
                ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        }

        cin>>n;
        for(int i=1;i<=n;i++)
                cin>>k[i];
        for(int i=1;i<=n;i++)
        {
                cin>>m[i];
                for(int j=0;j<m[i];j++)
                        cin>>e[i][j];
        }

        for(int i=0;i<nax*num;i++)
                point[i]=-1;

        for(int i=1;i<=n;i++)
                for(int j=0;j<num;j++)
                {
                        int x=geth(i,j);
                        int ni=e[i][x%m[i]];
                        int nj=rep(j+k[ni]);
                        int y=geth(ni,nj);
                        pok(0<=x && x<nax*num);
                        pok(0<=y && y<nax*num);
                        point[x]=y;
                        intr[y]=1;
                }
        for(int i=0;i<n*num;i++)
                if(intr[i]==0)
                        DFS(i);
        for(int i=0;i<n*num;i++)
                if(vis[i]==0)
                        DFS(i);
        int Q;
        cin>>Q;
        while(Q--)
        {
                int i,j;
                cin>>i>>j;
                j=rep(j);
                j=rep(j+k[i]);
                cout<<len[geth(i,j)]<<"\n";
        }

        return 0;
}
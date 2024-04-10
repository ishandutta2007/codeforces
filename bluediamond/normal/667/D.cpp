#include <bits/stdc++.h>

using namespace std;

const int N=3000+1;
int n,m;
vector<int>v[N];
vector<int>inv[N];
int s[N][N];
int sinv[N][N];

struct info
{
    int nod,val;
};

bool operator<(info a,info b)
{
    if(a.val!=b.val)
        return a.val<b.val;
    return a.nod<b.nod;
}

set<info>ans[2][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        inv[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        queue<int>q;
        /// 1 :
        q.push(i);
        s[i][i]=1;
        while(!q.empty())
        {
            int nod=q.front();
            q.pop();
            for(auto nou:v[nod])
            {
                if(s[i][nou]==0)
                {
                    s[i][nou]=s[i][nod]+1;
                    q.push(nou);
                }
            }
        }
        /// 2 :
        q.push(i);
        sinv[i][i]=1;
        while(!q.empty())
        {
            int nod=q.front();
            q.pop();
            for(auto nou:inv[nod])
            {
                if(sinv[i][nou]==0)
                {
                    sinv[i][nou]=sinv[i][nod]+1;
                    q.push(nou);
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ans[0][i].insert({j,s[i][j]});
            if(ans[0][i].size()==4) ans[0][i].erase(ans[0][i].begin());
        }
        for(int j=1;j<=n;j++)
        {
            ans[1][i].insert({j,sinv[i][j]});
            if(ans[1][i].size()==4) ans[1][i].erase(ans[1][i].begin());
        }
    }
    int ma=0;
    int f1=0,f2=0,f3=0,f4=0;
    for(int b=1;b<=n;b++)
    {
        for(int c=1;c<=n;c++)
        {
            if(b==c) continue;
            if(s[b][c]==0) continue;
            for(auto aux:ans[1][b])
            {
                int a=aux.nod;
                for(auto kek:ans[0][c])
                {
                    int d=kek.nod;
                    if(a==b) continue;
                    if(a==c) continue;
                    if(a==d) continue;
                    if(b==d) continue;
                    if(c==d) continue;
                    int cost=s[b][c]+aux.val+kek.val-3;
                    if(cost>ma)
                    {
                        ma=cost;
                        f1=a;
                        f2=b;
                        f3=c;
                        f4=d;
                    }
                }
            }
        }
    }
    cout<<f1<<" "<<f2<<" "<<f3<<" "<<f4<<"\n";
    return 0;
}
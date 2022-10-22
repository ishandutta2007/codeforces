#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 1005

int k[MAXN],m[MAXN],g[MAXN][10],res[MAXN][2520];
stack<pii> s;
bool mk[MAXN][2520];

void dfs(int i,int j)
{
    s.push(pii(i,j));
    mk[i][j]=1;
    int ji=(j+k[i])%2520;
    int xi=g[i][ji%m[i]];
    if(!res[xi][ji])
    {
        if(!mk[xi][ji])
            dfs(xi,ji);
        else
        {
            set<int> x;
            while(s.top()!=pii(xi,ji))
            {
                x.insert(s.top().first);
                s.pop();
            }

            x.insert(s.top().first);
            s.pop();

            while(!s.empty())
                s.pop();
            res[i][j]=x.size();
            return ;
        }
    }
    res[i][j]=res[xi][ji];
    while(!s.empty())
        s.pop();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> k[i];
        if(k[i]>=0)
            k[i]%=2520;
        else
        {
            k[i]=-k[i];
            k[i]%=2520;
            k[i]=(2520-k[i])%2520;
        }

    }

    for(int i=0;i<n;i++)
    {
        cin >> m[i];
        for(int j=0;j<m[i];j++)
        {
            cin >> g[i][j];
            g[i][j]--;
        }
    }

    for(int xxx=0;xxx<n;xxx++)
        for(int yyy=0;yyy<2520;yyy++)
            if(!mk[xxx][yyy])
            {
//                dfs(i,j);
                queue<pii> q;
                for(q.push(pii(xxx,yyy));!q.empty();q.pop())
                {
                    int i=q.front().first;
                    int j=q.front().second;
                    s.push(pii(i,j));
                    mk[i][j]=1;
                    int ji=(j+k[i])%2520;
                    int xi=g[i][ji%m[i]];
                    if(!res[xi][ji])
                    {
                        if(!mk[xi][ji])
                            q.push(pii(xi,ji));
                        else
                        {
                            set<int> x;
                            vector<pii> v;
                            while(s.top()!=pii(xi,ji))
                            {
                                v.push_back(s.top());
                                x.insert(s.top().first);
                                s.pop();
                            }

                            x.insert(s.top().first);
                            v.push_back(s.top());
                            s.pop();

                            while(!s.empty())
                            {
                                v.push_back(s.top());
                                s.pop();
                            }
                            int val=x.size();
                            for(auto y : v)
                                res[y.first][y.second]=val;
                        }
                    }
                    else
                    {
                        while(!s.empty())
                        {
                            res[s.top().first][s.top().second]=res[xi][ji];
                            s.pop();
                        }
                    }
                }
            }
    int q;
    cin >> q;
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        x--;
        if(y<0)
        {
            y=-y;
            y%=2520;
            y=(2520-y)%2520;
        }
        y%=2520;

        db(res[x][y])
    }

    return 0;
}
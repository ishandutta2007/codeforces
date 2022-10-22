#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 1005

int p[MAXN][MAXN][2];
bool mk[MAXN][MAXN];
char res[MAXN][MAXN];
pii parent[MAXN][MAXN];
vector<pii> ad;
int n;

pii operator+(pii a,pii b)
{
    return pii(a.first+b.first,a.second+b.second);
}

bool ok(pii a)
{
    return a.first>=0 && a.first<n && a.second>=0 && a.second<n;
}

bool dfs(int i,int j)
{
    mk[i][j]=1;
    bool re=0;
    pii ij=pii(i,j);
//    db("")
//    cout << i << ' ' << j << '\n';
    for(auto y : ad)
    {
        pii ny=ij+y;
        if(!ok(ny) || res[i][j])
            continue;
        if(p[ny.first][ny.second][0]!=-2)
            continue;
        if(!mk[ny.first][ny.second])
        {
//            parent[ny.first][ny.second]=pii(i,j);
            bool ok=dfs(ny.first,ny.second);
            if(ok && !re)
            {
                if(y==pii(0,-1))
                    res[i][j]='L';
                if(y==pii(0,1))
                    res[i][j]='R';
                if(y==pii(1,0))
                    res[i][j]='D';
                if(y==pii(-1,0))
                    res[i][j]='U';
                re=1;
            }
        }
        if(mk[ny.first][ny.second])
        {
//            cout << ny.first << ' ' << ny.second << '\n';
            if(y==pii(0,-1))
                res[i][j]='L';
            if(y==pii(0,1))
                res[i][j]='R';
            if(y==pii(1,0))
                res[i][j]='D';
            if(y==pii(-1,0))
                res[i][j]='U';
            re=1;
        }
    }
//    cout << i << ' ' << j << '\n';
//    db(re)
//    db("")
    return re;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            cin >> p[i][j][0] >> p[i][j][1];
            p[i][j][0]--;
            p[i][j][1]--;
        }

    ad.push_back(pii(0,1));
    ad.push_back(pii(0,-1));
    ad.push_back(pii(1,0));
    ad.push_back(pii(-1,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i==p[i][j][0] && j==p[i][j][1])
            {
//                cout << i << ' ' << j << '\n';
                queue<pii> q;
                mk[i][j]=1;
                res[i][j]='X';
                for(q.push(pii(i,j));!q.empty();q.pop())
                {
                    for(auto y : ad)
                    {
                        pii ny=q.front()+y;
//                        cout << ny.first << ' ' << ny.second << '\n';
                        if(ok(ny) && !mk[ny.first][ny.second])
                        {
                            if(p[ny.first][ny.second][0]==i && p[ny.first][ny.second][1]==j)
                            {
                                q.push(ny);
                                mk[ny.first][ny.second]=1;
                                if(y==pii(0,1))
                                    res[ny.first][ny.second]='L';
                                if(y==pii(0,-1))
                                    res[ny.first][ny.second]='R';
                                if(y==pii(-1,0))
                                    res[ny.first][ny.second]='D';
                                if(y==pii(1,0))
                                    res[ny.first][ny.second]='U';
                            }
                        }
                    }
                }
            }
//    for(int i=0;i<n;i++,cout << '\n')
//        for(int j=0;j<n;j++)
//            cout << res[i][j];
//    db("")

    bool oks=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(!mk[i][j] && p[i][j][0]==-2)
            {
                parent[i][j]=pii(-1,-1);
                oks&=dfs(i,j);
            }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(-2==p[i][j][0])
                mk[i][j]=0;

    queue<pii> q;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(-2==p[i][j][0] && -2==p[i][j][1] && res[i][j]!=0)
            {
                q.push(pii(i,j));
                mk[i][j]=1;
            }

    for(;!q.empty();q.pop())
    {
        for(auto y : ad)
        {
            pii ny=q.front()+y;
//                        cout << ny.first << ' ' << ny.second << '\n';
            if(ok(ny) && !mk[ny.first][ny.second])
            {
                if(p[ny.first][ny.second][0]==-2 && p[ny.first][ny.second][1]==-2 && !res[ny.first][ny.second])
                {
                    q.push(ny);
                    if(y==pii(0,1))
                        res[ny.first][ny.second]='L';
                    if(y==pii(0,-1))
                        res[ny.first][ny.second]='R';
                    if(y==pii(1,0))
                        res[ny.first][ny.second]='D';
                    if(y==pii(-1,0))
                        res[ny.first][ny.second]='U';
                }
            }
        }
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            oks&=(bool)res[i][j];
    if(oks)
    {
        db("VALID")

        for(int i=0;i<n;i++,cout << '\n')
            for(int j=0;j<n;j++)
                cout << res[i][j];
    }
    else
        db("INVALID")

//    for(int i=0;i<n;i++,cout << '\n')
//        for(int j=0;j<n;j++)
//            cout << res[i][j];
//    db("")

    return 0;
}
/**
3
-1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1
**/
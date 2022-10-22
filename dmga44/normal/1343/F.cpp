#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 205

vector<int> ls[MAXN],ps[MAXN];
int bs[MAXN],fs[MAXN],mk[MAXN],res[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,x;
        cin >> n;
        for(int i=0;i<=n;i++)
        {
            ps[i].clear();
            ls[i].clear();
        }
        for(int i=0;i<n-1;i++)
        {
            cin >> bs[i];
            for(int j=0;j<bs[i];j++)
            {
                cin >> x;
                ls[i].push_back(x);
                ps[x].push_back(i);
            }
        }

        for(int i=0;i<n-1;i++)
        {
            if(bs[i]!=2)
                continue;
//            db(i)
            for(int j=0;j<=n;j++)
            {
                fs[j]=bs[j];
                mk[j]=0;
            }

            res[0]=ls[i][0];
            res[1]=ls[i][1];
            mk[res[0]]=1;
            mk[res[1]]=1;
            if(ps[res[0]].size()>ps[res[1]].size())
                swap(res[0],res[1]);

            queue<int> q;
            for(auto y : ps[res[0]])
                fs[y]--;
            for(auto y : ps[res[1]])
            {
                fs[y]--;
                if(fs[y]==1)
                    q.push(y);
            }

            int cont=2;
            while(!q.empty())
            {
                if(q.size()>1)
                    break;
                int u=q.front();
                q.pop();

//                db(u)
                int v=-1;
                for(auto y : ls[u])
                    if(!mk[y])
                        v=y;

                for(auto y : ps[v])
                {
                    fs[y]--;
                    if(fs[y]==1)
                        q.push(y);
                }
                mk[v]=1;
                res[cont]=v;
                cont++;
            }
//            db(cont)
//            db("")

            if(cont==n)
            {
                vector<int> it(n+1);
                for(int i=0;i<n;i++)
                    it[res[i]]=i;
                bool ok=1;
                for(int j=0;j<n-1;j++)
                {
                    int mi=MAXN;
                    int ma=0;
                    for(auto y : ls[j])
                    {
                        mi=min(mi,it[y]);
                        ma=max(ma,it[y]);
                    }
                    ok&=((ma-mi+1)==bs[j]);
                }
                if(ok)
                {
                    for(int i=0;i<n;i++)
                        cout << res[i] << ' ';
                    cout << '\n';
                    break;
                }
            }
        }
    }

    return 0;
}
/**
5
2
2 1 2
5
2 2 3
2 1 2
2 1 4
2 4 5
6
3 2 5 6
2 4 6
3 1 3 4
2 1 3
4 1 2 4 6
7
3 1 2 6
4 1 3 5 6
2 1 2
3 4 5 7
6 1 2 3 4 5 6
3 1 3 6
5
2 2 5
3 2 3 5
4 2 3 4 5
5 1 2 3 4 5
**/
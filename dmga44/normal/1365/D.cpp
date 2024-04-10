#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define MAXN 55

char a[MAXN][MAXN];
bool mk[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        int cantg=0;
        bool ok=1;
        vector<pii> to_block;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mk[i][j]=0;
                cin >> a[i][j];
                if(a[i][j]=='G')
                    cantg++;
                else if(a[i][j]=='B')
                {
                    if(i)
                        to_block.push_back(pii(i-1,j));
                    if(i<n-1)
                        to_block.push_back(pii(i+1,j));
                    if(j)
                        to_block.push_back(pii(i,j-1));
                    if(j<m-1)
                        to_block.push_back(pii(i,j+1));
                }
            }
        }

        for(auto y : to_block)
        {
            if(a[y.f][y.s]=='B')
                continue;
            if(a[y.f][y.s]=='G')
                ok=0;
            a[y.f][y.s]='#';
        }

        queue<pii> q;
        if(a[n-1][m-1]!='#')
        {
            q.push(pii(n-1,m-1));
            mk[n-1][m-1]=1;
        }
        int actg=0;
        while(!q.empty())
        {
            pii u=q.front();
            q.pop();

            int i=u.f;
            int j=u.s;
            if(a[i][j]=='G')
                actg++;
            if(i && !mk[i-1][j] && a[i-1][j]!='#')
            {
                mk[i-1][j]=1;
                q.push(pii(i-1,j));
            }
            if(i<n-1 && !mk[i+1][j] && a[i+1][j]!='#')
            {
                mk[i+1][j]=1;
                q.push(pii(i+1,j));
            }
            if(j && !mk[i][j-1] && a[i][j-1]!='#')
            {
                mk[i][j-1]=1;
                q.push(pii(i,j-1));
            }
            if(j<m-1 && !mk[i][j+1] && a[i][j+1]!='#')
            {
                mk[i][j+1]=1;
                q.push(pii(i,j+1));
            }
        }

        ok&=(actg==cantg);
        if(ok)
            db("Yes")
        else
            db("No")
    }

    return 0;
}
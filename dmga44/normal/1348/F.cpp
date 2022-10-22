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
#define MAXN 200005

vector<pii> g[MAXN];
int xy[MAXN][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,u,v;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> u >> v;
        xy[i][0]=u;
        xy[i][1]=v;
        g[u].push_back(pii(v,i));
    }

    priority_queue<pii,vector<pii>,greater<pii> > pq;
    vector<int> res;
    vector<pii> sw;
    for(int i=1;i<=n;i++)
    {
        for(auto y : g[i])
            pq.push(y);

        if(pq.top().first>i && pq.size()>1)
        {
            pii x=pq.top();
            pq.pop();

            sw.push_back(pii(x.second,pq.top().second));
            pq.push(x);
        }
        res.push_back(pq.top().second);
        pq.pop();
    }

    if(!sw.size())
    {
        db("YES")
        vector<int> rr(n);
        for(int i=0;i<n;i++)
            rr[res[i]]=i+1;
        for(auto y : rr)
            cout << y << ' ';
        cout << '\n';
    }
    else
    {
        vector<pii> sw_ok;
        vector<int> rr(n);
        for(int i=0;i<n;i++)
            rr[res[i]]=i+1;
        for(auto y : sw)
            if(rr[y.second]<=xy[y.first][1])
                sw_ok.push_back(y);

        if(sw_ok.size())
        {
            db("NO")
            for(auto y : rr)
                cout << y << ' ';
            cout << '\n';
//            cout << sw_ok[0].first << ' ' << sw_ok[0].second << '\n';
            for(int i=0;i<n;i++)
            {
                if(res[i]==sw_ok[0].first)
                    res[i]=sw_ok[0].second;
                else if(res[i]==sw_ok[0].second)
                    res[i]=sw_ok[0].first;
            }
            for(int i=0;i<n;i++)
                rr[res[i]]=i+1;
            for(auto y : rr)
                cout << y << ' ';
            cout << '\n';
        }
        else
        {
            db("YES")
            for(auto y : rr)
                cout << y << ' ';
            cout << '\n';
        }
    }

    return 0;
}
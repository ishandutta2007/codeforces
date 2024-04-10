#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,pii> ppp;
#define MAXN 100005

bool mk[MAXN];

vector<pii> solve2(vector<ppp> v)
{
    vector<pii> ans;
    int n=v.size();
    int ant=-1;
    for(int i=0;i<n;i++)
        if(!mk[v[i].second.second])
        {
            if(ant==-1)
                ant=v[i].second.second;
            else
            {
                ans.push_back(pii(ant,v[i].second.second));
                mk[ant]=1;
                mk[v[i].second.second]=1;
                ant=-1;
            }
        }
    return ans;
}

vector<pii> solve(vector<ppp> x)
{
    int n=x.size();

    vector<pii> ans;
    vector<ppp> aux;
    for(int i=0;i<n;i++)
    {
        if(i && x[i].first.second!=x[i-1].first.second)
        {
            vector<pii> add=solve2(aux);
            aux.clear();
            for(auto y : add)
                ans.push_back(y);
        }
        aux.push_back(x[i]);
    }
    vector<pii> add=solve2(aux);
    aux.clear();
    for(auto y : add)
        ans.push_back(y);

    int ant=-1;
    for(int i=0;i<n;i++)
    {
        if(!mk[x[i].second.second])
        {
            if(ant==-1)
                ant=x[i].second.second;
            else
            {
                ans.push_back(pii(ant,x[i].second.second));
                mk[ant]=1;
                mk[x[i].second.second]=1;
                ant=-1;
            }
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,x,y,z;
    cin >> n;
    vector<ppp> v;
    for(int i=0;i<n;i++)
    {
        cin >> x >> y >> z;
        v.push_back(ppp(pii(x,y),pii(z,i)));
    }

    sort(v.begin(),v.end());

    vector<pii> ans;
    vector<ppp> aux;
    for(int i=0;i<n;i++)
    {
        if(i && v[i].first.first!=v[i-1].first.first)
        {
            vector<pii> add=solve(aux);
            aux.clear();
            for(auto y : add)
                ans.push_back(y);
        }
        aux.push_back(v[i]);
    }
    vector<pii> add=solve(aux);
    aux.clear();
    for(auto y : add)
        ans.push_back(y);

    int ant=-1;
    for(int i=0;i<n;i++)
        if(!mk[v[i].second.second])
        {
            if(ant==-1)
                ant=v[i].second.second;
            else
            {
                ans.push_back(pii(ant,v[i].second.second));
                mk[ant]=1;
                mk[v[i].second.second]=1;
                ant=-1;
            }
        }

    for(int i=0;i<n/2;i++)
        cout << ans[i].first+1 << ' ' << ans[i].second+1 << '\n';

    return 0;
}
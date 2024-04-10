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

vector<int> res;

void solve(int m,int n,int x)
{
    if(m==x)
        return ;
    if(m+2*n>=x)
    {
        res.push_back(x-m-n);
        solve(x,x-m,x);
    }
    else if(m+4*n<=x)
    {
        res.push_back(n);
        solve(m+2*n,2*n,x);
    }
    else
    {
        int dif=x-m;
        int nn=dif&1;
        int p1=dif/2;
        res.push_back(p1-n);
        res.push_back(nn);
        return ;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        solve(1,1,n);

        db(res.size())
        for(int i=0;i<res.size();i++)
            cout << res[i] << ' ';
        cout << '\n';
        res.clear();
    }

    return 0;
}
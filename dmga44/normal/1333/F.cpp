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
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 500005

bool mk[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> res;
    for(int i=n;i>0;i--)
    {
        vector<int> pos;
        for(int j=i;j<=n;j+=i)
            if(!mk[j])
                pos.push_back(j);
        if(pos.size()>1)
            for(int j=1;j<pos.size();j++)
            {
                res.push_back(i);
                mk[pos[j]]=1;
            }
    }

    reverse(all(res));

    for(int i=0;i<n-1;i++)
        cout << res[i] << ' ';
    cout << '\n';

    return 0;
}
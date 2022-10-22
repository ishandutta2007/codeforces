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
#define MAXN 200005

int ks[MAXN],c[MAXN];
vector<int> res[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k,x;
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        ks[x]++;
    }

    for(int i=0;i<k;i++)
        cin >> c[i+1];

    int ma=0;
    for(int i=k;i;i--)
    {
        int pos=-1;
        for(int po=(1<<17);po;po>>=1)
            if(po+pos<MAXN && res[po+pos].size()==c[i])
                pos+=po;
        pos++;
        while(ks[i])
        {
            while(ks[i] && res[pos].size()<c[i])
            {
                res[pos].push_back(i);
                ks[i]--;
            }
            pos++;
            ma=max(ma,pos);
        }
    }

    db(ma)
    for(int i=0;i<ma;i++)
    {
        cout << res[i].size() << ' ';
        for(auto y : res[i])
            cout << y << ' ';
        cout << '\n';
    }

    return 0;
}
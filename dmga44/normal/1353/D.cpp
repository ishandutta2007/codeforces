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
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;

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
        vector<int> res(n);
        priority_queue<pip,vector<pip>,less<pip> > pq;
        pq.push(pip(n,pii(0,-(n-1))));
        int i=1;
        while(!pq.empty())
        {
            int l=-pq.top().s.f;
            int r=-pq.top().s.s;
            pq.pop();
            int mid=(l+r)>>1;
//            db(mid)
            res[mid]=i;
            if(l<mid)
                pq.push(pip(mid-l,pii(-l,-(mid-1))));
            if(mid<r)
                pq.push(pip(r-mid,pii(-(mid+1),-r)));

            i++;
        }

        for(int i=0;i<n;i++)
            cout << res[i] << ' ';
        cout << '\n';
    }

    return 0;
}
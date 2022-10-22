#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define MAXN 200005

int f[MAXN],t[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--)
    {
        int n,a,fi;
        cin >> n;
        vector<int> dif;
        for(int i=0;i<n;i++)
        {
            cin >> a;
            if(!t[a])
                dif.push_back(a);
            t[a]++;
        }

        vector<pii> v;
        for(auto y : dif)
            v.push_back(pii(t[y],f[y]));

        sort(v.rbegin(),v.rend());

        priority_queue<int,vector<int>,less<int> > pq;
        int r1=0,r2=0,p=0;
        for(int i=v[0].first;i>=0;i--)
        {
            while(p<v.size() && v[p].first>=i)
            {
                pq.push(v[p].second);
                p++;
            }

            if(!pq.empty())
            {
                r1+=i;
                r2+=min(i,pq.top());
                pq.pop();
            }
        }

        cout << r1 << '\n';

        for(auto y : dif)
            f[y]=t[y]=0;
    }

    return 0;
}
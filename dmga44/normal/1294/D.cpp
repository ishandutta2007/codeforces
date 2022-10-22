#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<ll,pii> pip;
#define MAXN 400005

int f[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,x,a;
    cin >> n >> x;
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    for(int i=0;i<x;i++)
        pq.push(pii(0,i));
    for(int i=0;i<n;i++)
    {
        cin >> a;
        a%=x;
        f[a]++;
        pq.push(pii(f[a],a));
        while(pq.top().first!=f[pq.top().second])
            pq.pop();
        db(x*pq.top().first+pq.top().second)
    }

    return 0;
}
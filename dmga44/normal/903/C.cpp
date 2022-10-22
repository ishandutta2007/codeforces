#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 5005

int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    priority_queue<int,vector<int>,greater<int> > pq1,pq2;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        pq1.push(a[i]);
        pq2.push(a[i]);
    }

    int match=0;
    while(!pq1.empty())
    {
        while(!pq2.empty() && pq2.top()<=pq1.top())
            pq2.pop();
        if(!pq2.empty())
        {
            pq2.pop();
            match++;
        }
        pq1.pop();
    }

    db(n-match)

    return 0;
}
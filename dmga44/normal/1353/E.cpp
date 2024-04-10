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
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> ko(k),kt(k),ma(k),act(k);
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            kt[i%k]++;
            if(s[i]=='1')
            {
                sum++;
                ko[i%k]++;
            }
        }

        ll res=sum;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                int xj=(i/k)+1;
                int hj=act[i%k]+1;
                res=min(xj-hj-ma[i%k]+sum-hj,res);
            }
            act[i%k]+=(s[i]=='1');
            ma[i%k]=max(ma[i%k],(i/k)+1-2*act[i%k]);
        }
        db(res)
    }

    return 0;
}
/**
6
9 2
010001010
9 3
111100000
7 4
1111111
10 3
1001110101
1 1
1
1 1
0
**/
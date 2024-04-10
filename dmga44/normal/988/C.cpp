#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

map<int,pii> m;

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    int k;
    cin >> k;
    for(int uu=0;uu<k;uu++)
    {
        int n,sum=0,xi;
        cin >> n;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            cin >> xi;
            v.push_back(xi);
            sum+=xi;
        }

        for(int i=0;i<n;i++)
        {
            if(m[sum-v[i]]!=pii(0,0) && m[sum-v[i]].first!=uu+1)
            {
                db("YES")
                cout << m[sum-v[i]].first << ' ' << m[sum-v[i]].second << '\n';
                cout << uu+1 << ' ' << i+1 << '\n';
                return 0;
            }
            else
                m[sum-v[i]]=pii(uu+1,i+1);
        }
    }
    db("NO")

    return 0;
}
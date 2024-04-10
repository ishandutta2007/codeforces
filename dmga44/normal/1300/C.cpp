#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;

int f[30],last[30];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    int t;
//    cin >> t;
//    while(t--)
//    {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            cin >> v[i];
            for(int p=29;p>=0;p--)
                if(v[i]&(1<<p))
                {
                    f[p]++;
                    last[p]=i;
                }
        }

        int pos=-1;
        for(int i=29;i>=0;i--)
            if(f[i]==1 && pos==-1)
                pos=i;

        vector<int> res;
        res.push_back(v[last[pos]]);
        for(int i=0;i<n;i++)
            if(i!=last[pos])
                res.push_back(v[i]);
        for(int i=0;i<n;i++)
            cout << res[i] << ' ';
        cout << '\n';
//    }

    return 0;
}
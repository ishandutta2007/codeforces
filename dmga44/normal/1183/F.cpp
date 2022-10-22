#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define MAXN 200005

int f[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,x;
        cin >> n;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            cin >> x;
            if(!f[x])
            {
                f[x]=1;
                v.push_back(x);
            }
        }

        sort(v.begin(),v.end());

        n=v.size();
        int sum=0;
        for(int i=n-1;i>=0;i--)
        {
            vector<int> pos;
            for(int j=i;j>=0 && pos.size()<3;j--)
            {
                bool ok=1;
                for(auto y : pos)
                    ok&=((bool)(y%v[j]));
                if(ok)
                    pos.push_back(v[j]);
            }

            int sss=0;
            for(auto y : pos)
                sss+=y;
            sum=max(sum,sss);
        }

        db(sum)

        for(auto y : v)
            f[y]=0;
    }

    return 0;
}
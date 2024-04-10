#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<int> res={1,2};
        for(int d=-2;d<=0;d++)
        {
            int e=(-2-d);
            int a=(n+d);
            int b=(m+e);
            auto ch=[&](int x)
            {
                if(x>=3&&(a%x)==0&&(b%x)==0) res.push_back(x);
            };
            for(int i=1;i*i<=a;i++)
            {
                if((a%i)==0)
                {
                    ch(i);
                    if(i*i<a) ch(a/i);
                }
            }
        }
        ranges::sort(res);
        cout << res.size();
        for(int a:res) cout << " " << a;
        cout << "\n";
    }
    return 0;
}
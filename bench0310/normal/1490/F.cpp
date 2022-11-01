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
        int n;
        cin >> n;
        map<int,int> m;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            m[a]++;
        }
        vector<int> v;
        for(auto [a,b]:m) v.push_back(b);
        sort(v.begin(),v.end());
        int res=n;
        set<int> opt(v.begin(),v.end());
        for(int s:opt)
        {
            int now=0;
            for(int x:v)
            {
                if(x<s) now+=x;
                else now+=(x-s);
            }
            res=min(res,now);
        }
        cout << res << "\n";
    }
    return 0;
}
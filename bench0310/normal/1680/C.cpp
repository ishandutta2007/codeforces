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
        string s;
        cin >> s;
        int n=s.size();
        s="$"+s;
        int a=ranges::count(s,'1');
        deque<int> d;
        auto add=[&](int x)
        {
            while(!d.empty()&&d.back()>x) d.pop_back();
            d.push_back(x);
        };
        auto rm=[&](int x)
        {
            if(!d.empty()&&d.front()==x) d.pop_front();
        };
        vector<int> c(n+1,0);
        add(a);
        int res=a;
        for(int i=1;i<=n;i++)
        {
            c[i]=c[i-1]+(s[i]=='0');
            add(-c[i]+a+i);
            if(i-a>=0)
            {
                rm(-c[i-a]+a+(i-a));
                res=min(res,c[i]-c[i-a]);
            }
            res=min(res,c[i]+d.front()-i);
        }
        cout << res << "\n";
    }
    return 0;
}
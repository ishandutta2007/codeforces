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
        if(n==2)
        {
            cout << "-1\n";
            continue;
        }
        multiset<int> s;
        for(int i=1;i<=n;i++) s.insert(i);
        vector<array<int,2>> res;
        auto op=[&](int a,int b)
        {
            res.push_back({a,b});
            s.erase(s.find(a));
            s.erase(s.find(b));
            s.insert(a+b);
            s.insert(abs(a-b));
        };
        function<void(int,int)> go=[&](int m,int k)
        {
            if(m<=2) return;
            int p=(1<<(31-countl_zero(uint32_t(m))));
            for(int i=1;p+i<=m;i++) op(k*(p-i),k*(p+i));
            go(p-(m-p)-1,k);
            go(m-p,2*k);
        };
        go(n,1);
        for(int x:s)
        {
            if(s.count(x)>=2)
            {
                op(x,x);
                break;
            }
        }
        int opt=(*s.rbegin());
        while((*next(s.begin()))<opt)
        {
            int x=(*next(s.begin()));
            op(0,x);
            op(x,x);
        }
        op(0,opt);
        cout << res.size() << "\n";
        for(auto [a,b]:res) cout << a << " " << b << "\n";
    }
    return 0;
}
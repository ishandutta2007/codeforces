#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        vector<int> c(n+1,0);
        for(int i=2;i<=n;i++)
        {
            int p;
            cin >> p;
            c[p]++;
        }
        vector<int> v={1};
        for(int i=1;i<=n;i++) if(c[i]>0) v.push_back(c[i]);
        ranges::sort(v,greater<>());
        multiset<int> s;
        int cnt=v.size();
        int res=cnt;
        for(int i=1;i<=cnt;i++) s.insert(i+v[i-1]-1);
        for(int t=cnt+1;;t++)
        {
            while(!s.empty()&&(*s.begin())<t) s.erase(s.find(*s.begin()));
            if(s.empty()) break;
            res++;
            int x=(*s.rbegin());
            s.erase(s.find(x));
            s.insert(x-1);
        }
        cout << res << "\n";
    }
    return 0;
}
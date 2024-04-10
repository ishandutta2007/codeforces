#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    int idx=1;
    int res=0;
    auto mv=[&]()
    {
        res++;
        set<ll> s;
        s.insert(0);
        ll sum=0;
        while(idx<=n)
        {
            sum+=a[idx];
            if(s.find(sum)!=s.end()) break;
            idx++;
            s.insert(sum);
        }
    };
    while(idx<=n) mv();
    cout << res-1 << "\n";
    return 0;
}
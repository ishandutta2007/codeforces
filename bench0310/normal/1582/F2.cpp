#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=5000;
    const int S=(1<<13);
    vector<int> mn(S,N+1);
    vector<int> ready[S];
    auto upd=[&](int a,int val)
    {
        if(mn[a]<=val) return;
        for(int i=mn[a];i>val;i--) ready[i].push_back(a);
        mn[a]=val;
    };
    upd(0,0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        for(int p:ready[a]) upd(p^a,a);
        ready[a].clear();
    }
    vector<int> res;
    for(int i=0;i<S;i++) if(mn[i]<=N) res.push_back(i);
    cout << res.size() << "\n";
    for(int x:res) cout << x << " ";
    cout << "\n";
    return 0;
}
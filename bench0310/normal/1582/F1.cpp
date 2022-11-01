#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    const int N=(1<<9);
    vector<int> mn(N,N);
    mn[0]=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        for(int j=0;j<N;j++) if(mn[j]<a) mn[a^j]=min(mn[a^j],a);
    }
    vector<int> res;
    for(int i=0;i<N;i++) if(mn[i]<N) res.push_back(i);
    cout << res.size() << "\n";
    for(int x:res) cout << x << " ";
    cout << "\n";
    return 0;
}
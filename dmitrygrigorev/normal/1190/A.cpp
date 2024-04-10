#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(m);
    for (int i=0; i < m; i++) cin >> v[i];
    for (int i=0; i < m; i++) v[i]--;
    int u = 0;
    int ans = 0;
    while (u < m){
        int finish = u;
        while (finish < m){
            int A = (v[u]-u) / k;
            int B = (v[finish] - u)/k;
            if (A==B) finish++;
            else break;
        }
        ans++;
        u = finish;
    }
    cout << ans;
    return 0;
}
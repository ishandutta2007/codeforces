#include <bits/stdc++.h>
#define int long long
using namespace std;
int get(vector<int> &p, int num){
    int left = 0;
    int right = p.size() + 1;
    while (right - left > 1){
        int mid = (left + right) / 2;
        if (p[mid-1] < num) left = mid;
        else right = mid;
    }
    return left;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, k;
    cin >> n >> x >> k;
    vector<int> v(n), s(n), p(n);
    for (int i=0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i=0; i < n; i++) s[i] = v[i];
    for (int i=0; i < n; i++) p[i] = v[i];
    for (int i=0; i < n; i++){
        v[i] = v[i] / x + 1;
        s[i] = (s[i] / x + 1 - (s[i] % x == 0));
    }
    map<int, int> a;
    for (int i=0; i < n; i++) a[v[i]]++;
    int ans = 0;
    if (k == 0){
        for (int i=0; i < n; i++){
            if (p[i] % x == 0) continue;
            int nxt = (p[i] / x + 1) * x;
            int C = get(p, nxt);
            int C2 = get(p, p[i]);
            ans += C-C2;
        }
        cout << ans << endl;
        return 0;
    }
    for (int i=0; i < n; i++){
        int par = a[s[i]+k];
        ans += par;
    }
    cout << ans << endl;
    return 0;
}
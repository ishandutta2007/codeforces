#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    int w[60];
    int mn[60];
    for (int i=0; i < 60; i++) mn[i] = -1;
    vector<multiset<int> > v(60);
    for (int j=0; j < 60; j++) w[j] = 0;
    int b = 0;
    for (int i=0; i < q; i++){
        char kek;
        cin >> kek;
        if (kek == '+') b++;
        else b--;
        int num;
        cin >> num;
        int st = 0, what = 1;
        while (2*what <= num){
            what *= 2;
            st++;
        }
        if (kek == '+') v[st].insert(num);
        else v[st].erase(v[st].find(num));
        if (v[st].size()) mn[st] = (*v[st].begin());
        else mn[st] = -1;
        for (int j=st+1; j < 60; j++){
            if (kek == '+') w[j] += num;
            else w[j] -= num;
        }
        int ans = b;
        for (int j=0; j < 60; j++) if (2*w[j] < mn[j]) ans--;
        cout << ans << "\n";
    }
    return 0;
}
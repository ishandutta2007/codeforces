#include <bits/stdc++.h>
#define int long long
using namespace std;
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    for (int i=0; i < n; i++){
        vector<int> bot;
        for (int j=0; j <= i; j++) bot.push_back(v[j]);
        sort(bot.begin(), bot.end());
        reverse(bot.begin(), bot.end());
        int here = 0;
        for (int j=0; j < bot.size(); j += 2) here += bot[j];
        //if (i==2) cout << bot[0] << " " << bot[2] << endl;
        if (here > m){
            cout << i;
            return 0;
        }
    }
    cout << n;

}
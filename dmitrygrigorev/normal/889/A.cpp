#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i=0; i < n; i++) cin >> data[i];
    map<int, int> k;
    map<int, int> last;
    k[0] = 0;
    last[0] = 0;
    int ans = 1;
    for (int i=0; i < n; i++){
        int m = data[i];
        int room = k[m];
        if (last[room] == m){
            last[room] = i+1;
            k[i+1] = room;
        }
        else{
            k[i+1] = ans;
            last[ans] = i+1;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
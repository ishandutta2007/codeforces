#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        long long odda=0, evena=0, oddb=0, evenb=0;
        int n; cin >> n;
        while(n--) {
            int v; cin >> v;
            if(v%2) odda++;
            else evena++;
        }
        cin >> n;
        while(n--) {
            int v; cin >> v;
            if(v%2) oddb++;
            else evenb++;
        }
        cout << odda*oddb + evena*evenb << endl;
    }
}
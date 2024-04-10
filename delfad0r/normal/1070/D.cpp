#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
ifstream input_from_file("input.txt");
#define cin input_from_file
#endif

typedef long long LL;
typedef pair<int, int> II;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    LL k;
    cin >> n >> k;
    //~ cerr << n << ' ' << k << endl;
    LL ans = 0;
    LL prev = 0;
    for(int i=0; i<n; i++){
        LL curr; cin >> curr;
        LL d = (prev + k - 1) / k;
        ans += d;
        prev = curr - (d*k - prev);
        if(prev < 0) prev = 0;
    }
    ans += (prev + k - 1) / k;
    cout << ans << '\n';
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 200005;
int amt[N] = {0};

int main() {
    ios::sync_with_stdio(0);
    int n,s;
    cin >> n >> s; --s;

    if(n == 1) {
        int a;
        cin >> a;
        if(a != 0) cout << "1\n";
        else cout << "0\n";
        return 0;
    }

    int lg = -1;
    int add = 0;
    for(int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if(i == s) {
            if(a != 0) ++add;
            a = 0;
        }
        ++amt[a];
        lg = max(lg,a);
    }
    if(amt[0] == 0) {
        --amt[lg];
        ++amt[0];
    } else if(amt[0] > 1) {
        amt[N-1] += amt[0]-1;
        amt[0] = 1;
    }

    int best = n;

    int seen = amt[0];
    int n0 = 0;
    for(int i = 1; i < n; ++i) {
        seen += amt[i];
        if(amt[i] == 0) ++n0;
        int above = n-seen;
        best = min(best, above + max(0,n0-above));
    }
    cout << best+add << "\n";
    return 0;
}
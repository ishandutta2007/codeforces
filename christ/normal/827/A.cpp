#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 1e5+3, MOD = 1e9+7;
int len[MN];
char s[2000010];
int starts[2000010];
string t[MN];
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n;
    cin >> n; int lst = 0;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> t[i] >> k;
        len[i] = t[i].length();
        while (k--) {
            int a; cin >> a;
            if (len[i] > len[starts[a]]) starts[a] = i;
            lst = max(lst,a+len[i]-1);
        }
    }
    //cout << lst << endl;
    for (int i = 1; i <= lst; i++) {
        //cout << "i: " << i << " starts: " << starts[i] << endl;
        if (!starts[i]) cout << 'a';
        else {
            int j;
            for (j = i; j < i+len[starts[i]]; j++) {
                if (j != i && starts[j] && j + len[starts[j]] > i+len[starts[i]]) {i = j-1; goto oof;}
                cout << (t[starts[i]][j-i]);
            }
            i += len[starts[i]]-1;
            oof:;
        }
    }
    cout << endl;
    return 0;
}
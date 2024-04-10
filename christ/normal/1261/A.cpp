#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int MN = 1e5+2;
char s[MN], target[MN];
void solve () {
    int n,k;
    scanf ("%d %d\n%s",&n,&k,s);
    int bad = n/2-k+1;
    for (int i = 0; i < bad; i++) target[i] = '(';
    for (int i = bad; i < bad*2; i++) target[i] = ')';
    for (int i = bad*2; i < n; i++) target[i] = (i&1)?')':'(';
    vector<pii> swaps;
    for (int i = 0; i < n; i++) {
        if (s[i] != target[i]) {
            for (int j = i+1; j < n; j++) if (s[j] == target[i]) {
                reverse(s+i,s+j+1);
                swaps.push_back({
                    i,j
                });
                break;
            }
        }
    }
    printf ("%d\n",swaps.size());
    for (auto &p : swaps) printf ("%d %d\n",p.first+1,p.second+1);
}
int main () {
    int t;
    scanf ("%d",&t);
    while (t--) solve();
    return 0;
}
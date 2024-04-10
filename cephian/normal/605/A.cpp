#include <iostream>

using namespace std;

int n;
int p[100005];
bool seen[100005];
int sublen[100005];


int main() {
    cin >> n;
    fill(seen, seen+n+1, 0);
    fill(sublen, sublen+n+1, 0);
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> p[i];
        seen[p[i]] = 1;
        sublen[p[i]] = sublen[p[i]-1] + 1;
        ans = max(ans, sublen[p[i]]);
    }
    cout << n - ans << "\n";
    return 0;
}
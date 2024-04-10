#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;
typedef long long LL;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define pb push_back

#define X first
#define Y second
int n, m;
char str[55][55];
char pat[] = "face";

int main() {

    scanf("%d%d", &n, &m);
    int i, j, k;
    for (i = 0; i < n; i++) {
        scanf("%s", str[i]);
    }
    int cnt(0);
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < m - 1; j++) {
            vi v;
            if (strchr(pat, str[i][j]) == NULL) continue;
            int id = strchr(pat, str[i][j])- pat;
            v.pb(id);
            if (strchr(pat, str[i + 1][j]) == NULL) continue;
            id = strchr(pat, str[i + 1][j])- pat;
            v.pb(id);
            if (strchr(pat, str[i][j + 1]) == NULL) continue;
            id = strchr(pat, str[i][j + 1])- pat;
            v.pb(id);
            if (strchr(pat, str[i + 1][j + 1]) == NULL) continue;
            id = strchr(pat, str[i + 1][j + 1])- pat;
            
            v.pb(id);
            sort(v.begin(), v.end());
            for (k = 0; k < v.size() - 1; k++) if (v[k] == v[k + 1]) break;
            if (k == v.size() - 1) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
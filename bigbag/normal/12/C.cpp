#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111;

int n, m, a[max_n];
map <string, int> fr;
char s[max_n];
string s1[max_n];
vector <int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    scanf("%d\n");
    for (int i = 0; i < m; ++i) {
        gets(s);
        s1[i] = s;
        fr[s]++;
    }
    sort(a, a + n);
    sort(s1, s1 + m);
    int poz = 0;
    while (poz < m) {
        int cnt = 1;
        while (s1[poz] == s1[poz + 1] && poz < m) {
            cnt++;
            poz++;
        }
        poz++;
        q.push_back(cnt);
    }
    sort(q.begin(), q.end());
    reverse(q.begin(), q.end());
    int ans_min = 0, ans_max = 0;
    for (int i = 0; i < q.size(); ++i) {
        //cout << q[i] << ' ' << a[i] << endl;
        ans_min += q[i] * a[i];
        ans_max += q[i] * a[n - i - 1];
    }
    cout << ans_min << ' ' << ans_max;
    return 0;
}
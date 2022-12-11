#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

const int N = 1e3 + 10, O = 27;
int cnt, n, m;
bool v[O], ok[O], cur[O];
std::vector<int> empty, full;
std::string s, temp;

int main() {
    scanf("%d", &n);

    std::cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] != '*') {
            v[s[i] - 'a'] = true;
            full.push_back(i);
        } else {
            empty.push_back(i);
        }
    }

    for (int i = 0; i < 26; i++)
        ok[i] = !v[i];

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        static bool acc;
        acc = true;
        std::cin >> temp;
        for (int j : full)
            if (s[j] != temp[j]) {
                acc = false;
                break;
            }
        if (!acc)
            continue;
        for (int j : empty)
            if (v[temp[j] - 'a']) {
                acc = false;
                break;
            }
        if (!acc)
            continue;
        memset(cur, 0, sizeof cur);
        for (int j : empty)
            cur[temp[j] - 'a'] = true;
        for (int j = 0; j < 26; j++)
            if (!cur[j])
                ok[j] = false;
    }

    for (int i = 0; i < 26; i++)
        if (ok[i])
            cnt++;

    printf("%d\n", cnt);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 550000;
string st, ed, dap[N];
char s[N];
map<string, int> H;
int T;
int main() {
    ios::sync_with_stdio(0);
    while (gets(s)) {
        if (!strncmp(s, "\\begin", 6)) {
                st = s;
                break;
        }
        for (int i = 0; s[i]; i++) {
            if (s[i] == '{') {
                string cur;
                i++;
                while (s[i] != '}') cur.push_back(s[i]), i++;
                H[cur] = ++T;
            }
        }
    }
    int rnk = 0, illegal = 0;
    while (gets(s)) {
        if (!strncmp(s, "\\end", 4)) {
            ed = s;
            break;
        }
        rnk++;
        for (int i = 0; s[i]; i++) {
            if (s[i] == '{') {
                string cur;
                i++;
                while (s[i] != '}') cur.push_back(s[i]), i++;
                if (H[cur] != rnk) illegal = 1;
                dap[H[cur]] = s;
            }
        }
    }
    if (illegal == 0) {
        return puts("Correct"), 0;
    }
    cout<<"Incorrect\n";
    cout << st << endl;
    for (int i = 1; i <= T; i++) cout << dap[i] << endl;
    cout << ed << endl;
    return 0;
}
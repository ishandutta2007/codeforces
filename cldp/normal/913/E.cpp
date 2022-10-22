#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);

string f[1 << 8][3];

bool update(string &ans, string temp) {
    if (ans == "" || (temp.size() < ans.size() || (temp.size() == ans.size() && temp < ans))) {
        ans = temp;
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    f[0b11110000][0] = "x";
    f[0b11001100][0] = "y";
    f[0b10101010][0] = "z";

    while (true) {
        bool flag = false;
        for (int i = 0; i < 256; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (f[i][j] == "") continue;

                string temp = f[i][j];
                if (j > 0) temp = "(" + temp + ")";
                temp = "!" + temp;
                flag |= update(f[i ^ 255][0], temp);

                for (int a = 0; a < 256; ++a) {
                    for (int b = 0; b < 3; ++b) {
                        if (f[a][b] == "") continue;
                        for (int op = 1; op <= 2; ++op) {
                            string s = f[i][j];
                            if (j > op) s = "(" + s + ")";
                            string t = f[a][b];
                            if (b > op) t = "(" + t + ")";
                            string w = s + (op == 1 ? '&' : '|') + t;
                            flag |= update(f[op == 1 ? (i & a) : (i | a)][op], w);
                        }
                    }
                }
            }
        }
        if (!flag) break;
    }

    for (int i = 0; i < 256; ++i) {
        update(f[i][0], f[i][1]);
        update(f[i][0], f[i][2]);
    }

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string P;
        cin >> P;
        int z = 0;
        for (int j = 0; j < 8; ++j) {
            if (P[j] == '1') z += (1 << j);
        }
        cout << f[z][0] << endl;
    }

    return 0;
}
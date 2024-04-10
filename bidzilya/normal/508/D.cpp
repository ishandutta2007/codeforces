#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

#include <cassert>
using namespace std;

const string NO = "NO";
const string YES = "YES";

const int MAX_C = 62;

char GetChar(int num) {
    if (num < 26) {
        return num + 'a';
    } else if (num < 52) {
        return (num - 26) + 'A';
    } else {
        return (num - 52) + '0';
    }
}

int GetCharIndex(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 26;
    } else {
        return c - '0' + 52;
    }
}

const int MAX_N = MAX_C * MAX_C;

struct TEdge {
    int To;
    bool Used;
};

vector<TEdge> g[MAX_N];
int ptr[MAX_N];

int GetId(char c1, char c2) {
    int i1 = GetCharIndex(c1);
    int i2 = GetCharIndex(c2);
    return i1 * MAX_C + i2;
}

void FormResult(int v, string& result) {
    for (; ptr[v] < (int) g[v].size(); ) {
        TEdge& e = g[v][ptr[v]++];
        if (!e.Used) {
            e.Used = true;
            FormResult(e.To, result);
            result.push_back(GetChar(e.To % MAX_C));
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char s[4];

    for (int i = 0; i < n; ++i) {
        scanf(" %s", s);

        int id1 = GetId(s[0], s[1]);
        int id2 = GetId(s[1], s[2]);

        g[id1].push_back(TEdge{id2, false});
    }

    vector<int> inDegree(MAX_N, 0);
    vector<int> outDegree(MAX_N, 0);

    for (int i = 0; i < MAX_N; ++i) {
        for (const TEdge& e : g[i]) {
            ++outDegree[i];
            ++inDegree[e.To];
        }
    }

    int start = -1;
    int finish = -1;

    for (int i = 0; i < MAX_N; ++i) {
        if (inDegree[i] != outDegree[i]) {
            if (inDegree[i] == outDegree[i] + 1) {
                if (finish != -1) {
                    printf("%s\n", NO.c_str());
                    return 0;
                }
                finish = i;
            } else if (outDegree[i] == inDegree[i] + 1) {
                if (start != -1) {
                    printf("%s\n", NO.c_str());
                    return 0;
                }
                start = i;
            } else {
                printf("%s\n", NO.c_str());
                return 0;
            }
        }
    }

    if (start == -1) {
        for (int i = 0; i < MAX_N; ++i) {
            if (inDegree[i] > 0) {
                start = finish = i;
                break;
            }
        }
        assert(start != -1);
    }

    string result;
    FormResult(start, result);

    for (int i = 0; i < MAX_N; ++i) {
        for (const TEdge& e : g[i]) {
            if (!e.Used) {
                printf("%s\n", NO.c_str());
                return 0;
            }
        }
    }

    reverse(result.begin(), result.end());

    printf("%s\n", YES.c_str());
    printf("%c%c%s\n", GetChar(start / MAX_C), GetChar(start % MAX_C), result.c_str());

    return 0;
}
#include <iostream>
#include <vector>
#include <string>

#include <cassert>
using namespace std;

const int MAX_C = 27;
const char EMPTY = '#';
const long long INF = 1e18;

inline int CharToInt(char c) {
    if (isalpha(c)) {
        return c - 'a';
    }
    if (c == EMPTY) {
        return MAX_C - 1;
    }
    assert(false);
}

struct TNode {
    int Len;
    int SuffLink;
    int Next[MAX_C];
    long long Cost;
    int LenToEmpty;

    TNode(int len, int suffLink, long long cost, int lenToEmpty)
        : Len(len)
        , SuffLink(suffLink)
        , Cost(cost)
        , LenToEmpty(lenToEmpty)
    {
        for (int i = 0; i < MAX_C; ++i) {
            Next[i] = -1;
        }
    }
};

struct TAutomat {
public:
    void Reserve(int n) {
        Nodes.reserve(2 * n - 1);
    }

    void Init() {
        Nodes.clear();
        Nodes.push_back(TNode(0, -1, 0, 0));
        Last = 0;
    }

    void Extend(int sym, int cost, int lenToEmpty) {
        Nodes.push_back(TNode(Nodes[Last].Len + 1, -1, cost, lenToEmpty));
        int cur = Last;
        Last = Nodes.size() - 1;
        while (cur != -1 && Nodes[cur].Next[sym] == -1) {
            Nodes[cur].Next[sym] = Last;
            cur = Nodes[cur].SuffLink;
        }
        if (cur == -1) {
            Nodes[Last].SuffLink = 0;
        } else {
            int next = Nodes[cur].Next[sym];
            if (Nodes[next].Len == Nodes[cur].Len + 1) {
                Nodes[Last].SuffLink = next;
            } else {
                Nodes.push_back(Nodes[next]);
                int added = Nodes.size() - 1;
                Nodes[added].Len = Nodes[cur].Len + 1;
                Nodes[added].Cost = 0;
                Nodes[Last].SuffLink = Nodes[next].SuffLink = added;
                while (cur != -1 && Nodes[cur].Next[sym] == next) {
                    Nodes[cur].Next[sym] = added;
                    cur = Nodes[cur].SuffLink;
                }
            }
        }
    }

    void PushCost() {
        vector<vector<int>> vs(Nodes[Last].Len + 1);
        for (int i = 0; i < (int) Nodes.size(); ++i) {
            vs[Nodes[i].Len].push_back(i);
        }
        for (int i = vs.size() - 1; i >= 0; --i) {
            for (int v : vs[i]) {
                if (Nodes[v].SuffLink != -1) {
                    int link = Nodes[v].SuffLink;
                    Nodes[link].Cost += Nodes[v].Cost;
                    Nodes[link].LenToEmpty = min(Nodes[link].LenToEmpty, Nodes[v].LenToEmpty);
                }
            }
        }
    }

    long long GetResult() {
        long long result = 0;
        for (int i = 1; i < (int) Nodes.size(); ++i) {
            int len = min(Nodes[i].Len, Nodes[i].LenToEmpty);
            if (len > Nodes[Nodes[i].SuffLink].Len) {
                result = max(result, Nodes[i].Cost * len);
            }
        }
        return result;
    }
private:
    int Last;
    vector<TNode> Nodes;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<int> sc(n);
    for (int i = 0; i < n; ++i) {
        cin >> sc[i];
    }

    int m = 0;
    for (int i = 0; i < n; ++i) {
        m += s[i].length();
    }

    m += (n - 1);

    TAutomat a;
    a.Reserve(m);
    a.Init();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (int) s[i].length(); ++j) {
            a.Extend(CharToInt(s[i][j]), sc[i], j + 1);
        }
        if (i + 1 != n) {
            a.Extend(CharToInt(EMPTY), 0, 0);
        }
    }

    a.PushCost();

    cout << a.GetResult() << endl;

    return 0;
}
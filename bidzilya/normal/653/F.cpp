#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

const int MAX_LOG = 20;

const int MAX_C = 2;

inline int GetCharToInt(char c) {
    return c == '(' ? 0 : 1;
}

struct TNode {
    int Len;
    int SuffLink;
    vector<int> Next;
    int EndPos;

    TNode(int len, int suffLink)
        : Len(len)
        , SuffLink(suffLink)
        , Next(MAX_C, -1)
        , EndPos(-1)
    {
    }
};

class TAutomaton {
public:
    void Reserve(int n) {
        Nodes.reserve(2 * n - 1);
    }

    void Init() {
        Nodes.push_back(TNode{0, -1});
        Last = 0;
    }

    void Extend(char cc) {
        int c = GetCharToInt(cc);
        Nodes.push_back(TNode{Nodes[Last].Len + 1, -1});
        int cur = Last;
        Last = Nodes.size() - 1;
        while (cur != -1 && Nodes[cur].Next[c] == -1) {
            Nodes[cur].Next[c] = Last;
            cur = Nodes[cur].SuffLink;
        }
        if (cur == -1) {
            Nodes[Last].SuffLink = 0;
        } else {
            int next = Nodes[cur].Next[c];
            if (Nodes[next].Len == Nodes[cur].Len + 1) {
                Nodes[Last].SuffLink = next;
            } else {
                Nodes.push_back(Nodes[next]);
                int added = Nodes.size() - 1;
                Nodes[added].Len = Nodes[cur].Len + 1;
                Nodes[Last].SuffLink = Nodes[next].SuffLink = added;
                while (cur != -1 && Nodes[cur].Next[c] == next) {
                    Nodes[cur].Next[c] = added;
                    cur = Nodes[cur].SuffLink;
                }
            }
        }
        Nodes[Last].EndPos = Nodes[Last].Len - 1;
    }

    void BuildEndPos() {
        vector<vector<int>> vs(Nodes[Last].Len + 1);
        for (int i = 1; i < (int) Nodes.size(); ++i) {
            vs[Nodes[i].Len].push_back(i);
        }
        for (int i = vs.size() - 1; i >= 0; --i) {
            for (int v : vs[i]) {
                Nodes[Nodes[v].SuffLink].EndPos = Nodes[v].EndPos;
            }
        }
    }

    long long GetResult(const vector<vector<int>>& up) const {
        long long result = 0;
        for (int i = 1; i < (int) Nodes.size(); ++i) {
            int r = Nodes[i].EndPos;
            int l = r - Nodes[i].Len + 1;
            int m = r - Nodes[Nodes[i].SuffLink].Len;

            {
                for (int j = MAX_LOG - 1; j >= 0; --j) {
                    if (up[r][j] != -1) {
                        int x = up[r][j];
                        if (x > m) {
                            r = x - 1;
                        }
                    }
                }
            }

            {
                for (int j = MAX_LOG - 1; j >= 0; --j) {
                    if (r >= l && up[r][j] != -1) {
                        int x = up[r][j];
                        if (x >= l) {
                            result += (1 << j);
                            r = x - 1;
                        }
                    }
                }
            }
        }
        return result;
    }
private:
    int Last;
    vector<TNode> Nodes;
};

inline int GetBracketScore(char c) {
    return c == '(' ? 1 : -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;

    TAutomaton a;
    a.Reserve(n);
    a.Init();
    for (int i = 0; i < n; ++i) {
        a.Extend(s[i]);
    }

    a.BuildEndPos();

    vector<int> nextZero(n);
    vector<int> nextNeg(n);

    nextZero[0] = -1;
    nextNeg[0] = -1;
    if (s[0] == '(') {
        nextNeg[0] = 0;
    }
    for (int i = 1; i < n; ++i) {
        if (s[i] == '(') {
            nextZero[i] = -1;
            nextNeg[i] = i;
        } else {
            if (nextNeg[i - 1] == -1) {
                nextZero[i] = -1;
                nextNeg[i] = -1;
            } else {
                nextZero[i] = nextNeg[i - 1];
                if (nextZero[i] == 0) {
                    nextNeg[i] = -1;
                } else {
                    nextNeg[i] = nextNeg[nextZero[i] - 1];
                }
            }
        }
    }

    vector<vector<int>> up(n, vector<int>(MAX_LOG, -1));
    for (int i = 0; i < n; ++i) {
        if (nextZero[i] == -1) {
            continue;
        }
        up[i][0] = nextZero[i];
        for (int j = 1; j < MAX_LOG; ++j) {
            if (up[i][j - 1] == -1) {
                continue;
            }
            int k = up[i][j - 1];
            if (k == 0) {
                continue;
            }
            --k;
            if (up[k][j - 1] == -1) {
                continue;
            }
            up[i][j] = up[k][j - 1];
        }
    }

    cout << a.GetResult(up) << endl;

    return 0;
}
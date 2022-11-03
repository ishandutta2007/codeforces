#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include <cassert>
using namespace std;

#ifdef LOCAL
    #define LLD_SPEC "%lld"
#else
    #define LLD_SPEC "%I64d"
#endif

enum EOperation {
    O_AND,
    O_OR,
    O_XOR
};

int n, m;
map<string, int> indexMap;
vector<string> cnst;
vector<int> aidx, bidx;
vector<EOperation> ops;

vector<int> cur;

void AddVar(const string& s, int idx) {
    indexMap[s] = idx;
}

int GetIndex(const string& s) {
    if (s == "?") {
        return n;
    }
    return indexMap[s];
}

EOperation GetOperation(const string& s) {
    if (s == "OR") {
        return O_OR;
    } else if (s == "AND") {
        return O_AND;
    } else if (s == "XOR") {
        return O_XOR;
    } else {
        assert(false);
    }
}

int ApplyOp(int b1, int b2, EOperation op) {
    if (op == O_OR) {
        return b1 | b2;
    } else if (op == O_AND) {
        return b1 & b2;
    } else if (op == O_XOR) {
        return b1 ^ b2;
    } else {
        assert(false);
    }
}

int GetDigit(char digit) {
    return digit - '0';
}

int GetSum(int bit, int value) {
    cur[n] = value;
    for (int i = 0; i < n; ++i) {
        if (cnst[i].empty()) {
            cur[i] = ApplyOp(cur[aidx[i]], cur[bidx[i]], ops[i]);
        } else {
            cur[i] = GetDigit(cnst[i][bit]);
        }
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += cur[i];
    }
    return sum;
}

char GetMinBit(int bit) {
    if (GetSum(bit, 0) <= GetSum(bit, 1)) {
        return '0';
    } else {
        return '1';
    }
}

char GetMaxBit(int bit) {
    if (GetSum(bit, 0) >= GetSum(bit, 1)) {
        return '0';
    } else {
        return '1';
    }
}

void Solve() {
    cur.resize(n + 1);

    string minResult, maxResult;
    minResult.resize(m);
    maxResult.resize(m);
    for (int bit = 0; bit < m; ++bit) {
        minResult[bit] = GetMinBit(bit);
        maxResult[bit] = GetMaxBit(bit);
    }
    cout << minResult << endl;
    cout << maxResult << endl;
}

bool Read() {
    if (!(cin >> n >> m)) {
        return false;
    }
    cin.ignore();
    indexMap.clear();
    cnst.resize(n);
    aidx.resize(n);
    bidx.resize(n);
    ops.resize(n);
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);

        stringstream ss;
        ss << line;

        string var;
        ss >> var;

        AddVar(var, i);

        string buf;
        ss >> buf;

        if (count(line.begin(), line.end(), ' ') == 4) {
            string a, op, b;
            ss >> a >> op >> b;
            aidx[i] = GetIndex(a);
            ops[i] = GetOperation(op);
            bidx[i] = GetIndex(b);
        } else {
            ss >> cnst[i];
        }
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}
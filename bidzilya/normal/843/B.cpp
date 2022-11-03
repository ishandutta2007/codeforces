#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <numeric>
#include <set>
#include <map>
#include <string>
#include <random>
#include <vector>

#include <cassert>
#include <ctime>
using namespace std;

struct TNode {
    int Index;
    int Value;
    int Next;
};

const int S = 737;
const int L = 1998;

int GetRandom(int l, int r) {
    static mt19937 gen(42);
    return uniform_int_distribution<int>(l, r)(gen);
}

int n, start, x;

TNode GetNode(const int idx) {
    cout << "? " << idx + 1 << endl;

    TNode result;
    result.Index = idx;
    cin >> result.Value >> result.Next;
    if (result.Next != -1) {
        --result.Next;
    }

    return result;
}

void ShowResult(int value) {
    cout << "! " << value << endl;
}

void Solve() {
    TNode node = GetNode(start);
    if (node.Value >= x) {
        ShowResult(node.Value);
        return;
    }

    for (int i = 0; i < S; ++i) {
        const int idx = GetRandom(0, n - 1);
        const auto cur = GetNode(idx);
        if (cur.Value < x && cur.Value > node.Value) {
            node = cur;
        }
    }

    for (int i = 0; i < L - S; ++i) {
        if (node.Value >= x || node.Next == -1) {
            break;
        }
        node = GetNode(node.Next);
    }

    if (node.Value >= x) {
        ShowResult(node.Value);
    } else {
        ShowResult(-1);
    }
}

bool Read() {
    if (!(cin >> n >> start >> x)) {
        return false;
    }
    --start;
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
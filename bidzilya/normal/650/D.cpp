#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#include <cassert>
#include <cstdio>
using namespace std;

struct TNode {
    int Left;
    int Right;
    int Max;

    void Clear() {
        Left = Right = -1;
        Max = 0;
    }
};

const int MAX_NODE_COUNT = 18e6;

class TMemory {
public:
    static void Init(int maxNodeCount) {
        Nodes.reserve(maxNodeCount);
    }

    static int GetNewNode() {
        Nodes.push_back(TNode());
        Nodes.back().Clear();
        return Nodes.size() - 1;
    }

    static void SaveSize() {
        SavedSize = Nodes.size();
    }

    static void RollbackSize() {
        assert(SavedSize != -1);
        Nodes.resize(SavedSize);
    }

    static TNode& Get(int index) {
        return Nodes[index];
    }
private:
    static vector<TNode> Nodes;
    static int SavedSize;
};

vector<TNode> TMemory::Nodes;
int TMemory::SavedSize = -1;

TNode& GetNode(int index) {
    return TMemory::Get(index);
}

class TSegTree {
public:
    TSegTree()
    {
    }

    TSegTree(int root, int minPos, int maxPos)
        : Root(root)
        , MinPos(minPos)
        , MaxPos(maxPos)
    {
    }

    TSegTree(int minPos, int maxPos)
        : Root(TMemory::GetNewNode())
        , MinPos(minPos)
        , MaxPos(maxPos)
    {
    }

    TSegTree Set(int pos, int val) {
        int newRoot = TMemory::GetNewNode();
        GetNode(newRoot) = GetNode(Root);
        Set(newRoot, MinPos, MaxPos, pos, val);
        return TSegTree(newRoot, MinPos, MaxPos);
    }

    int Get(int l, int r) const {
        return Get(Root, MinPos, MaxPos, l, r);
    }
private:
    int Root;
    int MinPos;
    int MaxPos;

    void Set(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            GetNode(v).Max = max(GetNode(v).Max, val);
        } else {
            int tm = (tl + tr) >> 1;
            if (pos <= tm) {
                int oldLeft = GetNode(v).Left;
                int newLeft = TMemory::GetNewNode();
                GetNode(v).Left = newLeft;
                if (oldLeft != -1) {
                    GetNode(newLeft) = GetNode(oldLeft);
                }
                Set(GetNode(v).Left, tl, tm, pos, val);
            } else {
                int oldRight = GetNode(v).Right;
                int newRight = TMemory::GetNewNode();
                GetNode(v).Right = newRight;
                if (oldRight != -1) {
                    GetNode(newRight) = GetNode(oldRight);
                }
                Set(GetNode(v).Right, tm + 1, tr, pos, val);
            }
            GetNode(v).Max = max(GetMax(GetNode(v).Left), GetMax(GetNode(v).Right));
        }
    }

    int Get(int v, int tl, int tr, int l, int r) const {
        if (v == -1) {
            return 0;
        }
        if (tl == l && tr == r) {
            return GetNode(v).Max;
        } else {
            int tm = (tl + tr) >> 1;
            if (r <= tm) {
                return Get(GetNode(v).Left, tl, tm, l, r);
            } else if (l > tm) {
                return Get(GetNode(v).Right, tm + 1, tr, l, r);
            } else {
                return max(Get(GetNode(v).Left, tl, tm, l, tm), Get(GetNode(v).Right, tm + 1, tr, tm + 1, r));
            }
        }
    }

    int GetMax(int index) {
        return index == -1 ? 0 : GetNode(index).Max;
    }
};

vector<int> GetResultWithout(const vector<int>& a, int n, int minValue, int maxValue,
    const vector<TSegTree>& leftTree, const vector<TSegTree>& rightTree)
{
    vector<int> result(n, 0);

    int maxLen = leftTree.back().Get(minValue, maxValue);

    for (int i = 0; i < n; ++i) {
        result[i] = maxLen;
    }

    vector<int> leftResult(n);
    vector<int> rightResult(n);

    for (int i = 0; i < n; ++i) {
        leftResult[i] = (i == 0 || a[i] == minValue ? 1 : leftTree[i - 1].Get(minValue, a[i] - 1) + 1);
    }

    for (int i = 0; i < n; ++i) {
        rightResult[i] = (i == n - 1 || a[i] == maxValue ? 1 : rightTree[i + 1].Get(a[i] + 1, maxValue) + 1);
    }

    vector<int> count(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        if (leftResult[i] + rightResult[i] - 1 == maxLen) {
            ++count[leftResult[i]];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (leftResult[i] + rightResult[i] - 1 == maxLen && count[leftResult[i]] == 1) {
            --result[i];
        }
    }

    return result;
}

int main() {
    TMemory::Init(MAX_NODE_COUNT);

    int n, m;
    scanf("%d%d", &n, &m);

    vector<int> allValues;
    allValues.reserve(n + m);

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        allValues.push_back(a[i]);
    }
    vector<pair<int, int>> b(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &b[i].first, &b[i].second);
        --b[i].first;
        allValues.push_back(b[i].second);
    }

    sort(allValues.begin(), allValues.end());
    allValues.resize(unique(allValues.begin(), allValues.end()) - allValues.begin());
    unordered_map<int, int> mp;
    for (int i = 0; i < (int) allValues.size(); ++i) {
        mp[allValues[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
        a[i] = mp[a[i]];
    }
    for (int i = 0; i < m; ++i) {
        b[i].second = mp[b[i].second];
    }

    int minValue = 0;
    int maxValue = allValues.size() - 1;

    vector<TSegTree> leftTree(n);
    leftTree[0] = TSegTree(minValue, maxValue);
    leftTree[0] = leftTree[0].Set(a[0], 1);
    for (int i = 1; i < n; ++i) {
        leftTree[i] = leftTree[i - 1];
        int curVal = (a[i] == minValue ? 1 : leftTree[i].Get(minValue, a[i] - 1) + 1);
        leftTree[i] = leftTree[i].Set(a[i], curVal);
    }

    vector<TSegTree> rightTree(n);
    rightTree[n - 1] = TSegTree(minValue, maxValue);
    rightTree[n - 1] = rightTree[n - 1].Set(a[n - 1], 1);
    for (int i = n - 2; i >= 0; --i) {
        rightTree[i] = rightTree[i + 1];
        int curVal = (a[i] == maxValue ? 1 : rightTree[i].Get(a[i] + 1, maxValue) + 1);
        rightTree[i] = rightTree[i].Set(a[i], curVal);
    }

    vector<int> resultWithout = GetResultWithout(a, n, minValue, maxValue, leftTree, rightTree);

    for (int i = 0; i < m; ++i) {
        int pos = b[i].first;
        int val = b[i].second;

        int result = 0;
        {
            int curResult = 1;
            if (val != minValue && pos > 0) {
                curResult += leftTree[pos - 1].Get(minValue, val - 1);
            }
            if (val != maxValue && pos + 1 < n) {
                curResult += rightTree[pos + 1].Get(val + 1, maxValue);
            }

            result = max(result, curResult);
        }

        result = max(result, resultWithout[pos]);

        printf("%d\n", result);
    }

    return 0;
}
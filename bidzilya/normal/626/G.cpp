#include <iostream>
#include <vector>
#include <iomanip>

#include <cstdio>
#include <cassert>
#include <cmath>
using namespace std;

const int INF = 1e8 + 10;

struct TFrac {
    long long Num;
    long long Den;

    TFrac()
        : Num(0)
        , Den(1)
    {
    }

    TFrac(long long num, long long den)
        : Num(num)
        , Den(den)
    {
    }

    double GetValue() const {
        return 1.0 * Num / Den;
    }
};

ostream& operator << (ostream& outputStream, const TFrac& frac) {
    outputStream << "(" << frac.Num << " / " << frac.Den << ")";
    return outputStream;
}

bool operator < (const TFrac& lhs, const TFrac& rhs) {
    long long left = lhs.Num * rhs.Den;
    long long right = lhs.Den * rhs.Num;
    return left < right;
}

bool operator == (const TFrac& lhs, const TFrac& rhs) {
    long long left = lhs.Num * rhs.Den;
    long long right = lhs.Den * rhs.Num;
    return left == right;
}

bool operator <= (const TFrac& lhs, const TFrac& rhs) {
    return (lhs < rhs || lhs == rhs);
}

bool operator > (const TFrac& lhs, const TFrac& rhs) {
    return !(lhs <= rhs);
}

bool operator >= (const TFrac& lhs, const TFrac& rhs) {
    return !(lhs < rhs);
}

TFrac operator * (long long lhs, const TFrac& rhs) {
    return TFrac(rhs.Num * lhs, rhs.Den);
}

TFrac operator * (const TFrac& lhs, long long rhs) {
    return TFrac(lhs.Num * rhs, lhs.Den);
}

template<typename TGetter>
class THeap {
public:
    THeap()
        : Getter()
    {
    }

    void Push(int item) { 
        ExtendIndexes(item);
        Indexes[item] = T.size();
        T.push_back(item);
        GoUp(T.size() - 1);
    }

    int GetTop() const {
        return T[0];
    }

    void Shift(int v) {
        GoDownByIndex(v);
        GoUpByIndex(v);
    }

    void GoDownByIndex(int v) {
        GoDown(Indexes[v]);
    }

    void GoUpByIndex(int v) {
        GoUp(Indexes[v]);
    }

    bool IsEmpty() const {
        return GetSize() == 0;
    }

    int GetSize() const {
        return T.size();
    }
private:
    const int NOT_EXIST = -1;

    vector<int> T;
    vector<int> Indexes;

    TGetter Getter;

    inline int GetLeft(int v) {
        return 2 * v + 1;
    }

    inline int GetRight(int v) {
        return 2 * v + 2;
    }

    inline int GetUp(int v) {
        return (v - 1) / 2;
    }

    void GoUp(int v) {
        while (v > 0 && Getter(T[v]) > Getter(T[GetUp(v)])) {
            Swap(v, GetUp(v));
            v = GetUp(v);
        }
    }

    void GoDown(int v) {
        while (GetLeft(v) < GetSize() || GetRight(v) < GetSize()) {
            int left = GetLeft(v);
            int right = GetRight(v);
            int index = v;
            TFrac val = Getter(T[v]);
            if (left < GetSize() && Getter(T[left]) > val) {
                index = left;
                val = Getter(T[left]);
            }
            if (right < GetSize() && Getter(T[right]) > val) {
                index = right;
                val = Getter(T[right]);
            }
            if (index == v) {
                break;
            } else {
                Swap(index, v);
                v = index;
            }
        }
    }

    void Swap(int v, int u) {
        swap(T[v], T[u]);
        Indexes[T[v]] = v;
        Indexes[T[u]] = u;
    }

    void ExtendIndexes(int index) {
        while (Indexes.size() <= index) {
            Indexes.push_back(NOT_EXIST);
        }
    }
};

int n;
int t;
vector<int> p;
vector<int> l;

vector<int> usedCount;
int allUsedCount;

TFrac GetElem(int i, int j) {
    return TFrac(1LL * p[i] * l[i], 1LL * (l[i] + j) * (l[i] + j + 1));
}

double GetValue(int i) {
    return 1.0 * p[i] * usedCount[i] / (usedCount[i] + l[i]);
}

struct TNotUsedGetter {
public:
    TFrac operator () (int index) const {
        if (usedCount[index] == l[index]) {
            return TFrac(0, 1);
        } else {
            return GetElem(index, usedCount[index]);
        }
    }
};

struct TUsedGetter {
public:
    TFrac operator () (int index) const {
        if (usedCount[index] == 0) {
            return TFrac(-INF, 1);
        } else {
            return -1 * GetElem(index, usedCount[index] - 1);
        }
    }
};

THeap<TNotUsedGetter> notUsed;
THeap<TUsedGetter> used;

double result;

void Del(int i) {
    if (usedCount[i] == 0) {
        return;
    }
    result -= GetElem(i, usedCount[i] - 1).GetValue();
    --usedCount[i];
    --allUsedCount;
    notUsed.GoUpByIndex(i);
    used.GoDownByIndex(i);
}

void Add(int i) {
    result += GetElem(i, usedCount[i]).GetValue();
    ++usedCount[i];
    ++allUsedCount;
    notUsed.GoDownByIndex(i);
    used.GoUpByIndex(i);
}

bool DelBest() {
    if (allUsedCount == 0) {
        return false;
    }
    Del(used.GetTop());
    return true;
}

bool AddBest() {
    if (allUsedCount == t) {
        return false;
    }
    int index = notUsed.GetTop();
    if (usedCount[index] == l[index]) {
        return false;
    }
    Add(index);
    return true;
}

void Init() {
    usedCount.assign(n, 0);
    allUsedCount = 0;
    for (int i = 0; i < n; ++i) {
        notUsed.Push(i);
        used.Push(i);
    }
    result = 0.0;
    for (int itr = 0; itr < t; ++itr) {
        if (!AddBest()) {
            break;
        }
    }
}

void Inc(int i) {
    result -= GetValue(i);
    ++l[i];
    notUsed.Shift(i);
    used.Shift(i);
    result += GetValue(i);
    DelBest();
    DelBest();
    while (AddBest()) {
    }
}

void Dec(int i) {
    if (usedCount[i] == l[i]) {
        Del(i);
    }
    result -= GetValue(i);
    --l[i];
    notUsed.Shift(i);
    used.Shift(i);
    result += GetValue(i);
    DelBest();
    DelBest();
    while (AddBest()) {
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    scanf("%d%d%d", &n, &t, &q);

    p.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
    }

    l.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &l[i]);
    }

    Init();

    while (q--) {
        int tp;
        int x;
        scanf("%d%d", &tp, &x);
        --x;
        if (tp == 1) {
            Inc(x);
        } else {
            Dec(x);
        }
        printf("%.17f\n", result);
    }

    return 0;
}
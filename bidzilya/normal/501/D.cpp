#include <bits/stdc++.h>
using namespace std;


struct Orderer
{
    Orderer(int n) :
        n(n)
    {
        s.resize(4 * n);
        Build();
    }

    void Build(int v, int tl, int tr)
    {
        if (tl == tr) {
            s[v] = 1;
        } else {
            int tm = (tl + tr) >> 1;
            Build(2 * v, tl, tm);
            Build(2 * v + 1, tm + 1, tr);
            s[v] = s[2 * v] + s[2 * v + 1];
        }
    }

    void Build()
    {
        Build(1, 0, n - 1);
    }

    void Inverse(int v, int tl, int tr, int pos)
    {
        if (tl == tr) {
            s[v] = 1 - s[v];
        } else {
            int tm = (tl + tr) >> 1;
            if (pos <= tm) {
                Inverse(2 * v, tl, tm, pos);
            } else {
                Inverse(2 * v + 1, tm + 1, tr, pos);
            }
            s[v] = s[2 * v] + s[2 * v + 1];
        }
    }

    void Inverse(int pos)
    {
        Inverse(1, 0, n - 1, pos);
    }

    int GetSum(int v, int tl, int tr, int l, int r)
    {
        if (l == tl && r == tr) {
            return s[v];
        } else {
            int tm = (tl + tr) >> 1;

            if (r <= tm) {
                return GetSum(2 * v, tl, tm, l, r);
            } else if (l > tm) {
                return GetSum(2 * v + 1, tm + 1, tr, l, r);
            } else {
                return GetSum(2 * v, tl, tm, l, tm) +
                       GetSum(2 * v + 1, tm + 1, tr, tm + 1, r);
            }
        }
    }

    int GetIndexOfElem(int elem)
    {
        return GetSum(1, 0, n - 1, 0, elem) - 1;
    }

    int GetElemWithSum(int v, int tl, int tr, int sum)
    {
        if (tl == tr) {
            return tl;
        } else {
            int tm = (tl + tr) >> 1;

            if (s[2 * v] >= sum) {
                return GetElemWithSum(2 * v, tl, tm, sum);
            } else {
                return GetElemWithSum(2 * v + 1, tm + 1, tr, sum - s[2 * v]);
            }
        }
    }

    int GetElemWithIndex(int index)
    {
        return GetElemWithSum(1, 0, n - 1, index + 1);
    }

    vector<int> s;
    int n;
};


vector<int> FromPermToOrder(const vector<int>& perm)
{
    int n = perm.size();
    Orderer ord(n);
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        res[i] = ord.GetIndexOfElem(perm[i]);
        ord.Inverse(perm[i]);
    }
    return res;
}

vector<int> FromOrderToPerm(const vector<int>& ord)
{
    int n = ord.size();
    Orderer orderer(n);
    vector<int> perm(n);
    for (int i = 0; i < n; ++i) {
        perm[i] = orderer.GetElemWithIndex(ord[i]);
        orderer.Inverse(perm[i]);
    }
    return perm;
}

vector<int> ReadVector(int n)
{
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        cin >> res[i];
    }
    return res;
}

void ShowVector(const vector<int>& a)
{
    for (int i = 0; i < (int) a.size(); ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> p1 = ReadVector(n),
                p2 = ReadVector(n);

    vector<int> v1 = FromPermToOrder(p1),
                v2 = FromPermToOrder(p2);

    vector<int> v(v1.begin(), v1.end());
    for (int i = 0; i < n; ++i) {
        v[i] += v2[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        int up = n - i;
        if (i > 0) {
            v[i - 1] += v[i] / up;
        }
        v[i] %= up;
    }

    ShowVector(FromOrderToPerm(v));

    return 0;
}
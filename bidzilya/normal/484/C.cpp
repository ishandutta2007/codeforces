#include <bits/stdc++.h>
using namespace std;

typedef vector<int> Perm;

int n;
vector<int> temp;
vector<int> shift_perm;
vector<int> dsort_perm;
vector<int> ed_perm;

void SetShiftPerm()
{
    shift_perm[n - 1] = 0;
    for (int i = 0; i + 1 < n; ++i) {
        shift_perm[i] = i + 1;
    }
}

void SetDSortPerm(int k, int d)
{
    for (int i = k; i < n; ++i) {
        dsort_perm[i] = i;
    }
    for (int i = 0; i < d; ++i) {
        temp[i] = 0;
    }
    int rem = 0;
    for (int i = 0; i < k; ++i) {
        ++temp[rem];
        ++rem;
        if (rem == d) {
            rem = 0;
        }
    }
    for (int i = 1; i < d; ++i) {
        temp[i] += temp[i - 1];
    }
    for (int i = d - 1; i > 0; --i) {
        temp[i] = temp[i - 1];
    }
    temp[0] = 0;
    rem = 0;
    for (int i = 0; i < k; ++i) {
        dsort_perm[temp[rem]++] = i;
        ++rem;
        if (rem == d) {
            rem = 0;
        }
    }
}

Perm operator * (const Perm& a, const Perm& b)
{
    int n = a.size();
    Perm r(n);
    for (int i = 0; i < n; ++i) {
        r[i] = a[b[i]];
    }
    return r;
}

void SetEdPerm()
{
    for (int i = 0; i < n; ++i) {
        ed_perm[i] = i;
    }
}

Perm BinaryPow(const Perm& a, int pw)
{
    if (pw == 0) {
        return ed_perm;
    }
    if ((pw & 1) == 1) {
        return a * BinaryPow(a, pw - 1);
    }
    return BinaryPow(a * a, pw >> 1);
}

ostream& operator << (ostream& output_stream, const Perm& a)
{
    output_stream << "[";
    for (int i = 0; i < (int) a.size(); ++i) {
        output_stream << a[i];
        if (i + 1 != a.size()) {
            output_stream << ", ";
        }
    }
    output_stream << "]";
    return output_stream;
}

const int kMaxLen = 1e6;

char s[2][kMaxLen + 1];

int main()
{
    /*
    freopen("input.txt", "w", stdout);
    cout << "z" << endl;
    cout << 1000000 << endl;
    for (int i = 0; i < 1000000; ++i) {
        cout << 1 << " " << 1 << endl;
    }
    return 0;
    */
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%s", s[0]);
    n = strlen(s[0]);
    s[1][n] = '\0';

    ed_perm.resize(n);
    SetEdPerm();

    shift_perm.resize(n);
    SetShiftPerm();

    dsort_perm.resize(n);

    temp.resize(n);

    int m;
    scanf("%d", &m);

    int cur = 0;
    for (int itr = 0; itr < m; ++itr) {
        int k, d;
        scanf("%d%d", &k, &d);
        SetDSortPerm(k, d);
        Perm t = BinaryPow(dsort_perm * shift_perm, n - k + 1) * BinaryPow(shift_perm, k - 1);
        int nxt = 1 - cur;
        for (int i = 0; i < n; ++i) {
            s[nxt][i] = s[cur][t[i]];
        }
        swap(cur, nxt);
        printf("%s\n", s[cur]);
    }

    return 0;
}
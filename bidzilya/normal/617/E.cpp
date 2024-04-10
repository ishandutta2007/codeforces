#include <iostream>
#include <vector>
#include <algorithm>

#include <cassert>
using namespace std;

#define count count124124

struct TQuery {
    int l;
    int r;
    int id;
};

const int MAX_K = 3e6 + 10;

int n, k;
vector<int> a;

long long glResult;

int count[MAX_K];

int leftBorder;
int rightBorder;

void Init() {
    glResult = (a[0] == k);
    leftBorder = rightBorder = 0;
    for (int i = 0; i < MAX_K; ++i) {
        count[i] = 0;
    }
    count[0] = 1;
}

void Show() {
    cout << leftBorder << ".." << rightBorder << endl;
    cout << glResult << endl;
    for (int i = 0; i < MAX_K; ++i) {
        if (count[i] != 0) {
            cout << i << ": " << count[i] << endl;
        }
    }
    cout << endl;
}

void IncRightBorder() {
    count[a[rightBorder]] += 1;
    rightBorder += 1;
    glResult += count[k ^ a[rightBorder]];
    assert(leftBorder <= rightBorder);
}

void DecRightBorder() {
    glResult -= count[k ^ a[rightBorder]];
    rightBorder -= 1;
    count[a[rightBorder]] -= 1;
    assert(leftBorder <= rightBorder);
}

void IncLeftBorder() {
    if (leftBorder == 0) {
        count[0] -= 1;
        glResult -= (count[k] + (a[rightBorder] == k));
    } else {
        count[a[leftBorder - 1]] -= 1;
        glResult -= (count[k ^ a[leftBorder - 1]] + (a[rightBorder] == (k ^ a[leftBorder - 1])));
    }
    leftBorder += 1;
    assert(leftBorder <= rightBorder);
}

void DecLeftBorder() {
    leftBorder -= 1;
    if (leftBorder == 0) {
        glResult += (count[k] + (a[rightBorder] == k));
        count[0] += 1;
    } else {
        glResult += (count[k ^ a[leftBorder - 1]] + (a[rightBorder] == (k ^ a[leftBorder - 1])));
        count[a[leftBorder - 1]] += 1;
    }
    assert(leftBorder <= rightBorder);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m >> k;

    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        a[i] ^= a[i - 1];
    }

    vector<TQuery> q(m);
    for (int i = 0; i < m; ++i) {
        cin >> q[i].l >> q[i].r;
        --q[i].l;
        --q[i].r;
        q[i].id = i;
    }

    sort(q.begin(), q.end(), [] (const TQuery& lhs, const TQuery& rhs) {
        return lhs.l < rhs.l;
    });

    Init();

    vector<long long> result(m);
    const int S = 300;
    for (int blockIndex = 0; blockIndex * S < n; ++blockIndex) {
        int blockLeft = blockIndex * S;
        int blockRight = (blockIndex + 1) * S;

        int il = m;
        int ir = -1;

        for (int i = 0; i < m; ++i) {
            if (q[i].l >= blockLeft && q[i].l < blockRight) {
                il = min(il, i);
                ir = max(ir, i + 1);
            }
        }

        if (il == m) {
            continue;
        }

        sort(q.begin() + il, q.begin() + ir, [] (const TQuery& lhs, const TQuery& rhs) {
            return lhs.r < rhs.r;
        });

        for (int i = il; i < ir; ++i) {
            while (rightBorder < q[i].r) {
                IncRightBorder();
            }
            while (leftBorder > q[i].l) {
                DecLeftBorder();
            }
            while (rightBorder > q[i].r) {
                DecRightBorder();
            }
            while (leftBorder < q[i].l) {
                IncLeftBorder();
            }
            result[q[i].id] = glResult;
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << result[i] << '\n';
    }
    cout.flush();

    return 0;
}
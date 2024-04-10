#include <bits/stdc++.h>

using namespace std;

int a[30];
int b[30];
int c[30];
int n;

template <typename Callback>
void p(int sa, int sb, int sc, int curLevel, int tarLevel, long long int path, Callback callback) {
    // // clog << curLevel << ' ' << tarLevel << endl;
    if (curLevel == tarLevel) {
        callback(sa, sb, sc, path);
        return;
    }

    p(sa + a[curLevel], sb + b[curLevel], sc, curLevel + 1, tarLevel, path * 3, callback);
    p(sa + a[curLevel], sb, sc + c[curLevel], curLevel + 1, tarLevel, path * 3 + 1, callback);
    p(sa, sb + b[curLevel], sc + c[curLevel], curLevel + 1, tarLevel, path * 3 + 2, callback);
}

struct k {
    int c;
    long long int path;

    bool operator <(const k &other) {
        if (c < other.c) return true;
        return false;
    }
};

map<pair<int, int>, k> kmap;

void cba(int sa, int sb, int sc, long long int path) {
    k thing;
    thing.c = sa + sb + sc;
    thing.path = path;
    // clog << (sa - sb) << ' ' << (sb - sc) << ' ' << thing.c << '\n';
    if (kmap.count(make_pair(sa - sb, sb - sc))) {
        k t = kmap[make_pair(sa - sb, sb - sc)];
        if (t.c > thing.c) return;
    }
    kmap[make_pair(sa - sb, sb - sc)] = thing;
}

long long int resultPathA;
long long int resultPathB;
long int maxSum = LONG_MIN;
void cbb(int sa, int sb, int sc, long long int path) {
    if (kmap.count(make_pair(sb - sa, sc - sb ))) {
        k ret = kmap[make_pair(sb - sa, sc - sb )];
        // clog << ret.c << ' ' << (sa + sb + sc) << '\n';
        // clog << ret.path << path;
        if (sa + sb + sc + ret.c > maxSum) {
            maxSum = sa + sb + sc + ret.c;
            resultPathA = ret.path;
            resultPathB = path;
        }
    }
}


void print(long long int mask) {
    const string t[] = {"LM", "LW", "MW"};
    while (mask > 1) {
        cout << t[mask % 3] << '\n';
        mask /= 3;
    }
}


int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    ifstream cin("heros.inp");
    ofstream cout("heros.out");
    #endif

    cin >> n;


    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    int halfLevel = n / 2;
    p(0, 0, 0, 0, halfLevel, 1, cba);
    p(0, 0, 0, halfLevel, n, 1, cbb);

    if (maxSum <= LONG_MIN) {
        cout << "Impossible\n";
    } else {
        const string t[] = {"LM", "LW", "MW"};
        stack<int> step;
        long long int mask;
        mask = resultPathB;
        while (mask > 1) {
            step.push(mask % 3);
            mask /= 3;
        }
        mask = resultPathA;
        while (mask > 1) {
            step.push(mask % 3);
            mask /= 3;
        }
        while (!step.empty()) {
            cout << t[step.top()] << '\n';
            step.pop();
        }
    }

    #ifndef ONLINE_JUDGE
    cin.close();
    cout.close();
    #endif

    return 0;
}
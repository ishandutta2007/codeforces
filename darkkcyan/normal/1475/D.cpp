#include <bits/stdc++.h>
using namespace std;

int n, m;
struct Application {
    int memory;
    int conven;
    void setMemory(int memory) {
        this->memory = memory;
    }
    void setConven(int conven) {
        this->conven = conven;
    }
    friend ostream& operator << (ostream &out, const Application &app) {
        out << app.memory << ' ' << app.conven << '\n';
        return out;
    }
};

const int N = 2e5 + 10;
Application app[N];
auto check(int mid) {
    long long mem = 0, con = 0;
    for(int i = 1; i <= n; ++i) {
        mem += app[i].memory;
        con += app[i].conven;
        if (mem >= m) {
            if (con <= mid) return true;
            int milestone = i + 1;
            for(int j = i; j >= 1; --j) if (app[j].conven == 2) {
                while (milestone <= n && app[milestone].conven == 2) milestone ++;
                if (milestone > n) return false;
                con --;
                mem = mem - app[j].memory + app[milestone].memory;
                if (con <= mid) {
                    if (mem >= m) return true;
                    int m2 = milestone + 1, tmp = 0;
                    for(int k = j-1; k >= 1; --k) if (app[k].conven == 2) {
                        while (m2 <= n && app[m2].conven == 2) m2 ++;
                        if (m2 <= n) tmp = app[m2].memory;
                        m2 ++;
                        while (m2 <= n && app[m2].conven == 2) m2 ++;
                        if (m2 <= n) tmp += app[m2].memory;
                        if (tmp > app[k].memory) mem += -app[k].memory + tmp;
                        else return false;
                        if (mem >= m) return true;
                        m2 ++;
                    }
                    return false;
                }
                milestone ++;
            }
            return false;
        }
    }
    return false;
}
auto solve() {
    cin >> n >> m;
    int val;
    for(int i = 1; i <= n; ++i) {
        cin >> val;
        app[i].setMemory(val);
    }
    for(int i = 1; i <= n; ++i) {
        cin >> val;
        app[i].setConven(val);
    }
    sort(app + 1, app + 1 + n, [](auto &a, auto &b) -> bool {
        if (a.memory > b.memory) return true;
        return false;
    });
    int low = 0, high = 4e5, ans = -1;
    while (low <= high) {
        int mid = low + high >> 1;
        if (check(mid)) {
            ans = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    int ntest;
    cin >> ntest;
    for(; ntest; ntest --) {
        auto ans = solve();
        cout << ans << '\n';
    }
}
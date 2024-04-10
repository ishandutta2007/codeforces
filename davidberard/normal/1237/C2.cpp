#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

int n;

int sb;

struct pt {
    int x, y, z, i;
    pt () {}
    pt (int a, int b, int c, int d) : x(a), y(b), z(c), i(d) {}
    bool operator< (const pt& o) const {
        if (sb == 0) {
            return x < o.x;
        } else if (sb == 1) {
            return y < o.y;
        } else {
            return z < o.z;
        }
    }
};

const int N =50500;

pt pts[N];
vector<pt> vpts;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; ++i) {
        cin >> pts[i].x >> pts[i].y >> pts[i].z;
        pts[i].i = i;
        vpts.push_back(pts[i]);
    }
    sort(vpts.begin(), vpts.end());

    vector<int> used(n+1, 0);
    int echs = 0;
    int lx = -1e9;
    pt xv(-1e9, -1e9, -1e9, 0);
    for (int i=0; i<vpts.size(); ++i) {
        vector<pt> cur;
        cur.push_back(vpts[i]);
        //cerr << " in " << cur.back().i << endl;
        lx = vpts[i].x;
        while (i+1 < vpts.size() && vpts[i+1].x == lx) {
            cur.push_back(vpts[++i]);
            //cerr << " adding " << cur.back().i << endl;
        }
        sb = 1;
        sort(cur.begin(), cur.end());
        if (xv.x != -1e9) {
            pii best(1e9, -1);
            for (int j=0; j<cur.size(); ++j) {
                if (cur[j].x == -1e9) continue;
                best = min(best, pii(abs(cur[j].x-xv.x) + abs(cur[j].y-xv.y) + abs(cur[j].z-xv.z), j));
            }
            assert(best.first != 1e9);
            cur[best.second].x = -1e9;
            cout << cur[best.second].i << " " << xv.i << "\n";
            assert (used[cur[best.second].i]++ == 0);
            assert (used[xv.i]++ == 0);
            ++echs;
            xv.x = -1e9;
        }
        pt extra(-1e9, -1e9, -1e9, 0);
        int ly = -1e9;
        for (int j=0; j<cur.size(); ++j) {
            ly = cur[j].y;
            vector<pt> row;
            ////cerr << "  to row " << cur[j].x << " " << cur[j].y << " " << cur[j].z << endl;
            row.push_back(cur[j]);
            //cerr << "  rw " << cur[j].i << endl;
            while (j+1 < cur.size() && cur[j+1].y == ly) {
                row.push_back(cur[++j]);
                //cerr << "  ww " << cur[j].i << endl;
                ////cerr << "  to row " << cur[j].x << " " << cur[j].y << " " << cur[j].z << endl;
            }
            //////cerr << " -- " << j << " " << row.size() << "\n";
            
            sb = 2;
            sort(row.begin(), row.end());

            if (extra.x != -1e9) {
                //cerr << " TRYING EXTRA" << endl;
                pii best(1e9, -1);
                for (int k=0; k<row.size(); ++k) {
                    if (row[k].x == -1e9) continue;
                    best = min(best, pii(abs(row[k].z-extra.z), k));
                }
                if (best.first != 1e9) {
                    row[best.second].x = -1e9;
                    ////cerr << "!! " << endl;
                    cout << row[best.second].i << " " << extra.i << "\n";
                    assert (used[extra.i]++ == 0);
                    assert (used[row[best.second].i]++ == 0);
                    ++echs;
                    extra.x = -1e9;
                }
            }

            int last = -1;
            for (int k=0; k<row.size(); ++k) {
                if (row[k].x == -1e9) continue;
                if (last >= 0) {
                    //////cerr << "!! " << endl;
                    cout << row[k].i << " " << row[last].i << "\n";
                    assert (used[row[k].i]++ == 0);
                    assert (used[row[last].i]++ == 0);
                    ++echs;
                    last = -1;
                } else {
                    last = k;
                }
            }

            if (last >= 0) {
                assert(extra.x == -1e9);
                extra = row[last];
                ////cerr << " SETTING EXTRA" << endl;
            }
        }

        if (extra.x != -1e9) {
            assert(xv.x == -1e9);
            xv = extra;
            ////cerr << " UNLOADING EXTRA " << endl;
        }
    }

    return 0;
}
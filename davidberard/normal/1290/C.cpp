#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int N = 300300;
vector<int> members[N*2];
int group[N*2];
int taken[N*2];
int invalid[N*2];
int has_out[N*2];
int high_count[N*2];

/*unordered_set<int> in[N*2];
unordered_set<int> out[N*2];*/

int init[N];

vector<int> relevant[N];
int n, k;
int amt;

int eval() {
    return amt;
}

void remove_cur(int u) {
    int gu = (taken[group[u*2]] ? group[u*2] : group[u*2+1]);
    
    if (!taken[gu]) return;

    taken[gu] = 0;
    amt -= high_count[gu];
}

void insert_best(int u) {
    if (taken[group[u*2]]) return;
    if (taken[group[u*2+1]]) return;

    int ngu = 0;
    if (has_out[group[u*2]]) {
        ngu = group[u*2+1];
    } else if (has_out[group[u*2+1]]) {
        ngu = group[u*2];
    } else {
        if (high_count[group[u*2]] < high_count[group[u*2+1]]) {
            ngu = group[u*2];
        } else if (high_count[group[u*2]] > high_count[group[u*2+1]]) {
            ngu = group[u*2+1];
        } else {
            ngu = min(group[u*2], group[u*2+1]);
        }
    }

    assert(ngu);
    assert(!invalid[ngu]);

    taken[ngu] = 1;
    amt += high_count[ngu];
}

void insert_up(int u) {
    remove_cur(u);
    has_out[group[u*2]]++;
    insert_best(u);
}

void insert_down(int u) {
    remove_cur(u);
    has_out[group[u*2+1]]++;
    insert_best(u);
}

void group_together(int u, int v) {
    //cerr << " TRY GROUP " << u << " " << v << endl;
    if (group[u] == group[v]) return;
    if (members[group[u]].size() < members[group[v]].size()) {
        swap(u, v);
    }
    int gu = group[u];
    int gv = group[v];
    assert(!invalid[gu]);
    assert(!invalid[gv]);
    invalid[gv] = 1;

    //cerr << "   REMOVE G " << gv << endl;
    high_count[gu] += high_count[gv];

    for (auto& x : members[gv]) {
        members[gu].push_back(x);
        group[x] = gu;
    }



    //cerr << "   G " << gu << " : ";
    for (auto& x : members[gu]) {
        //cerr << x << " ";
    }
    //cerr << endl;


    /*
    for (auto& x : in[gv]) {
        out[x].erase(gv);
        out[x].insert(gu);
        in[gu].insert(x);
    }
    for (auto& x : out[gv]) {
        in[x].erase(gv);
        in[x].insert(gu);
        out[gu].insert(x);
    }
    */
    has_out[gu] |= has_out[gv];
}


void insert_equal(int u, int v) {
    // handle bookkeeping
    remove_cur(u);
    remove_cur(v);
    
    group_together(u*2, v*2);
    group_together(u*2+1, v*2+1);

    insert_best(u);
    insert_best(v);
}

void insert_either(int u, int v) {
    remove_cur(u);
    remove_cur(v);

    group_together(u*2, v*2+1);
    group_together(u*2+1, v*2);

    insert_best(u);
    insert_best(v);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    string ss;
    cin >> ss;
    for (int i=1; i<=n; ++i) {
        init[i] = ss[i-1]-'0';
    }
    for (int i=1; i<=k; ++i) {
        int k;
        cin >> k;
        for (int j=0; j<k; ++j) {
            int x;
            cin >> x;
            relevant[x].push_back(i);
        }
        group[i*2] = i*2;
        group[i*2+1] = i*2+1;
        members[i*2].push_back(i*2);
        members[i*2+1].push_back(i*2+1);
        high_count[i*2+1] = 1;
        taken[i*2] = 1;
    }
    for (int i=1; i<=n; ++i) {
        if (relevant[i].size() == 1) {
            if (init[i]) {
                insert_down(relevant[i][0]);
            } else {
                insert_up(relevant[i][0]);
            }
        } else if (relevant[i].size() == 2) {
            if (init[i]) {
                insert_equal(relevant[i][0], relevant[i][1]);
            } else {
                //cerr <<  "  EITHER " << endl;
                insert_either(relevant[i][0], relevant[i][1]);
            }
        }
        cout << eval() << "\n";
    }
    return 0;
}
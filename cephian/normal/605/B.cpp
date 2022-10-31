#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int n, m;

int start[100005], endd[100005];

vector<pii> yes, no;

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int e, t;
        cin >> e >> t;
        if(t == 1) yes.push_back(pii(e, i));
        else no.push_back(pii(e, i));
    }
    sort(yes.begin(), yes.end());
    sort(no.begin(), no.end());

    int nind = no.size()-1;
    int v = 1;
    for(int i = yes.size()-1; i >=0; --i) {
        start[yes[i].second] = v;
        endd[yes[i].second] = v+1;
        int u = v+2;
        while(u <= n && nind >= 0 && no[nind].first >= yes[i].first) {
            start[no[nind].second] = v;
            endd[no[nind].second] = u;
            ++u;
            --nind;
        }
        ++v;
    }
    if(nind != -1) {
        cout << "-1\n";
        return 0;
    }
    for(int i = 1; i <= m; ++i)
        cout << start[i] << " " << endd[i] << "\n";
    return 0;
}
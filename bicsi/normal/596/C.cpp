#include <bits/stdc++.h>

using namespace std;

int A[500000];
typedef pair<int, int> Pair;

unordered_map<int, vector<Pair>> Bucket;
Pair Sol[500000];
int Max[500000], W[500000];
unordered_map<int, int> Ind[500000];

int main() {
    int n, x, y;
    cin>>n;

    int maxy = 0;

    for(int i=1; i<=n; i++) {
        cin>>x>>y;
        Bucket[y-x].push_back({x, y});
        Max[y] = max(Max[y], x);
        maxy = max(maxy, y);
    }

    for(auto &V : Bucket) {
        sort(V.second.begin(), V.second.end());
    }

    for(int i=1; i<=n; i++) {
        cin>>W[i];
    }

    for(int i=n; i; i--) {
        if(Bucket[W[i]].empty()) {
            cout<<"NO";
            return 0;
        }

        Sol[i] = Bucket[W[i]].back();
        Ind[Sol[i].first][Sol[i].second] = i;

        Bucket[W[i]].pop_back();
    }

    for(int i=maxy; i>=0; i--) {
        for(int j=Max[i]; j>=0; j--) {
            if(Ind[i][j+1] && Ind[i][j+1] < Ind[i][j] || Ind[i+1][j] && Ind[i+1][j] < Ind[i][j]) {
                cout<<"NO";
                return 0;
            }
        }
    }

    cout<<"YES\n";
    for(int i=1; i<=n; i++) {
        cout<<Sol[i].first<<" "<<Sol[i].second<<'\n';
    }
}
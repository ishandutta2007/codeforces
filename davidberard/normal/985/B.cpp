#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N, M; cin >> N >> M;
    vector<vector<int>> arr(N, vector<int>(M, 0));
    vector<int> sum(M, 0);
    for(int i=0;i<N;++i) {
        string s;
        cin >> s;
        for(int j=0;j<M;++j) {
            arr[i][j] = s[j]-'0';
            sum[j] += arr[i][j];
        }
    }
    for(int i=0;i<N;++i) {
        bool good = true;
        for(int j=0;j<M;++j) {
            if(sum[j] - arr[i][j] <= 0) {
                good = false;
                break;
            }
        }
        if(good) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
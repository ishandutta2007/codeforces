#include <bits/stdc++.h>
#define int long long
using namespace std;
const int K = 1 << 20;
vector<vector<int> > data;
vector<int> nums, ans;
vector<bool> used;
int val[K];
int d, v, maximum, G;
vector<int> th;
void dfs(int vertex, int d, int last){
    if (d > maximum){
        v = vertex;
        maximum = d;
    }
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (used[to] || to == last) continue;
        dfs(to, d+1, vertex);
    }
}
bool dfs2(int vertex, int d, int last){
    bool ret = false;
    if (d > maximum){
        maximum = d;
        if (d <= 1) v = vertex;
        ret = true;
    }
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (used[to] || to == last) continue;
        bool res = dfs2(to, d+1, vertex);
        if (res && d == maximum / 2){
            v = vertex;
        }
        if (res) ret = true;
    }
    return ret;
}
void dfs_c(int vertex, int N, int last){
    N ^= (1 << nums[vertex]);
    th.push_back(N);
    val[N]++;
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (used[to] || to == last) continue;
        dfs_c(to, N, vertex);
    }
}
int dfs_res(int vertex, int N, int last){
    N ^= (1 << nums[vertex]);
    int R = 0;
    for (int i=0; i < 21; i++){
        int X = 1 << i;
        if (i == 20) X = 0;
        int XR = N^X;
        R += val[XR];
        if (XR == 0) G += val[XR] + 1;
        else G += val[XR];
    }
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (last == to || used[to]) continue;
        R += dfs_res(to, N, vertex);
    }
    ans[vertex] += R;
    return R;
}
void get_centroid(int vertex){
    maximum = -1;
    dfs(vertex, 0, -1);
    if (maximum == 0) return;
    maximum = -1;
    dfs2(v, 0, -1);
    int C = v;
    //cout << C << endl;
    //cout << C << endl;
    vector<vector<int> > comp;
    G = 0;
    val[0] = 1;
    for (int i=0; i < data[C].size(); i++){
        int to = data[C][i];
        if (used[to]) continue;
        //cout << to << endl;
        th.clear();
        dfs_c(to, 0, C);
        comp.push_back(th);
    }
    //cout << 123 << endl;
    int counter = 0;
    //cout << val[0] << endl;
    for (int i=0; i < data[C].size(); i++){
        int to = data[C][i];
        if (used[to]) continue;
        for (int j=0; j < comp[counter].size(); j++){
            val[comp[counter][j]]--;
        }
        counter++;
        dfs_res(to, (1<<nums[C]), C);
        for (int j=0; j < comp[counter-1].size(); j++){
            val[comp[counter-1][j]]++;
        }
    }
    for (int i=0; i < comp.size(); i++){
        for (int j=0; j < comp[i].size(); j++){
            val[comp[i][j]] = 0;
        }
    }
    val[0] = 0;
    ans[C] += G/2;
    used[C] = true;
    for (int i=0; i < data[C].size(); i++){
        int to = data[C][i];
        if (used[to]) continue;
        get_centroid(to);
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i=0; i < n; i++){
        vector<int> help;
        data.push_back(help);
        used.push_back(false);
        ans.push_back(1);
    }
    for (int i=0; i < n-1; i++){
        int A, B;
        cin >> A >> B;
        data[A-1].push_back(B-1);
        data[B-1].push_back(A-1);
    }
    for (int i=0; i < n; i++){
        char ch;
        cin >> ch;
        nums.push_back(ch - 'a');
    }
    for (int i=0; i < K; i++) val[i] = 0;
    get_centroid(0);
    for (int i=0; i < n; i++) cout << ans[i] << " ";
    return 0;
}
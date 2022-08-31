#include <bits/stdc++.h>
using namespace std;
deque<bool> matrix[300][300];
deque<bool> fin[300][300];
struct Move{int xa; int ya; int xb; int yb;};
int n, m;
vector<Move> ans;
void print(){
    cout << ans.size() << "\n";
    for (int i=0; i < ans.size(); i++){
        cout << ans[i].xa +1 << " " << ans[i].ya +1 << " " << ans[i].xb + 1 << " " << ans[i].yb+1 << "\n";
    }
    exit(0);
}
void Transmit(int i, int j){
    for (int p=((int) (fin[i][j].size()))-1; p >= 0; p--){
        bool el = fin[i][j][p];
        if (el){
            if (j != m-1){
                ans.push_back({n-1, m-1, n-1, j});
            }
            if (n-1 != i) ans.push_back({n-1, j, i, j});
        }
        else{
            if (i != 0) ans.push_back({0, 0, i, 0});
            if (j != 0) ans.push_back({i, 0, i, j});
        }
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("1.txt", "r", stdin);
    cin >> n >> m;
    for (int i=0; i < n; i++){
        for (int j=0; j < m; j++){
            string s;
            cin >> s;
            deque<bool> q;
            for (int p=0; p < s.size(); p++){
                if (s[p] == '0') q.push_back(false);
                else q.push_back(true);
            }
            matrix[i][j] = q;
        }
    }
    while (matrix[0][0].size()){
        bool el = matrix[0][0].back();
        ans.push_back({0, 0, 0, m-1});
        matrix[0][0].pop_back();
        matrix[0][m-1].push_front(el);
    }
    while (matrix[n-1][m-1].size()){
        bool el = matrix[n-1][m-1].back();
        ans.push_back({n-1, m-1, 0, m-1});
        matrix[n-1][m-1].pop_back();
        matrix[0][m-1].push_front(el);
    }
    for (int i=m-1; i >= 0; i--){
        for (int j=0; j < n; j++){
            if (i==0 && j==0) continue;
            if (i==m-1 && j==n-1) continue;
            while (matrix[j][i].size()){
                bool el = matrix[j][i].back();
                matrix[j][i].pop_back();
                if (!el){
                    if (j!=0){
                        ans.push_back({j, i, 0, i});
                    }
                    if (i!=0) ans.push_back({0, i, 0, 0});
                    matrix[0][0].push_front(el);
                }
                else{
                    if (i != m-1){
                        ans.push_back({j, i, j, m-1});
                    }
                    if (j != n-1) ans.push_back({j, m-1, n-1, m-1});
                    matrix[n-1][m-1].push_front(el);
                }
            }
        }
    }
    for (int i=0; i < n; i++){
        for (int j=0; j < m; j++){
            string s;
            cin >> s;
            deque<bool> q;
            for (int p=0; p < s.size(); p++){
                if (s[p] == '0') q.push_back(false);
                else q.push_back(true);
            }
            fin[i][j] = q;
        }
    }
    for (int i=m-1; i >= 0; i--){
        for (int j=0; j < n; j++){
            if (i==0 && j==0) continue;
            if (i==m-1 && j==n-1) continue;
            if (i==0 && j==n-1) continue;
            if (i==m-1 && j==0) continue;
            Transmit(j, i);
        }
    }
    for (int p= ((int) (fin[0][0].size())) -1; p >= 0; p--){
        bool el = fin[0][0][p];
        if (el){
            ans.push_back({n-1, m-1, n-1, 0});
        }
        else{
            ans.push_back({0, 0, n-1, 0});
        }
    }
    for (int p=((int) (fin[n-1][m-1].size()))-1; p >= 0; p--){
        bool el = fin[n-1][m-1][p];
        if (el){
            ans.push_back({n-1, m-1, 0, m-1});
        }
        else{
            ans.push_back({0, 0, 0, m-1});
        }
    }
    Transmit(n-1, 0);
    Transmit(0, m-1);
    for (int i=0; i < fin[0][0].size(); i++) ans.push_back({n-1, 0, 0, 0});
    for (int i=0; i < fin[n-1][m-1].size(); i++) ans.push_back({0, m-1, n-1, m-1});
    print();


}
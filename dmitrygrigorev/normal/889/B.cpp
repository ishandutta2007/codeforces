#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> nexts(26), prevs(26);
signed main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    for (int i=0; i < 26; i++) nexts[i] = -1;
    for (int i=0; i < 26; i++) prevs[i] = -1;
    vector<bool> has(26);
    fill(has.begin(), has.end(), false);
    for (int i=0; i < n; i++){
        for (int j=0; j < v[i].size() - 1; j++){
            int F = v[i][j] - 'a';
            int S = v[i][j+1] - 'a';
            has[F] = true;
            if (nexts[F] != -1 && nexts[F] != S){
                cout << "NO" << endl;
                return 0;
            }
            if (prevs[S] != -1 && prevs[S] != F){
                cout << "NO" << endl;
                return 0;
            }
            prevs[S] = F;
            nexts[F] = S;
        }
        has[v[i][v[i].size()-1]-'a'] = true;
    }
    vector<bool> used(26);
    vector<vector<int> > ans;
    set<int> gd;
    int C = 0;
    for (int i=0; i < 26; i++){
        if (has[i]) C++;
        if (prevs[i] != -1 || !has[i]) continue;
        fill(used.begin(), used.end(), false);
        vector<int> th;
        int now = i;
        while (now != -1){
            gd.insert(now);
            if (used[now]){
                cout << "NO" << endl;
                return 0;
            }
            used[now] = true;
            th.push_back(now);
            now = nexts[now];
        }
        ans.push_back(th);
    }
    if (ans.size() == 0 || gd.size() != C){
        cout << "NO" << endl;
        return 0;
    }
    sort(ans.begin(), ans.end());
    for (int i=0; i < ans.size(); i++){
        for (int j=0; j < ans[i].size(); j++){
            char ch = ans[i][j] + 'a';
            cout << ch;
        }
    }
    return 0;
}
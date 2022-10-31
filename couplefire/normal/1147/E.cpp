#include <bits/stdc++.h>
using namespace std;

int norm(int x, int n){
    return (x%n+n)%n;
}

string check;

string ask(vector<pair<int, int>> v){
    if(v.size() == 0) return "";
    cout << "Q" << " ";
    cout << v.size() << " ";
    for(auto x : v){
        cout << x.first+1 << " " << x.second+1 << " ";
    }
    cout << endl;
    string res = "";
    cin >> res;
    // for(auto x : v){
    //     if(check[x.first] == check[x.second]) res += "1";
    //     else res += "0";
    // }
    // cout << res << endl;
    return res;
}

void solve(int t){
    int n; 
    cin >> n;
    if(n == 1){
        cout << "A " << "1 " << "0 " << "0 " << endl;
        cout << 1 << endl;
        return;
    }
    if(n == -1) exit(0);
    // cin >> check;
    // n = check.size();
    int next[n];
    int prev[n];
    set<pair<int, int>> got;
    // if(t == 0) exit(0);
    for(int i = 0; i<20; i++){
        if(got.size() == n) break;
        bool visited[n];
        fill(visited, visited+n, false);
        vector<pair<int, int>> toAsk;
        for(int j = 0; j<n; j++){
            if(visited[j] || visited[norm(j+1, n)]) continue;
            if(got.count({j, norm(j+1, n)})) continue;
            toAsk.push_back({j, norm(j+1, n)});
            visited[j] = 1;
            visited[norm(j+1, n)] = 1;
            got.insert({j, norm(j+1, n)});
        }
        string res = ask(toAsk);
        // cout << res << endl;
        // if(res == "-1") exit(0);
        for(int j = 0; j<toAsk.size(); j++){
            next[toAsk[j].first] = res[j]-'0';
            prev[toAsk[j].second] = res[j]-'0';
        }
    }
    vector<int> good;
    for(int i = 0; i<n; i++){
        if(prev[i] == 0) good.push_back(i);
    }
    int m = good.size();
    // cout << m << endl;
    if(m == 0){
        cout << "A ";
        cout << n << " " << "0 " << "0 " << endl;
        for(int i = 0; i<n; i++) cout << i+1 << " ";
        cout << endl;
        return;
    }
    int next2[m];
    int prev2[m];
    set<pair<int, int>> got2;
    for(int i = 0; i<20; i++){
        if(m == 2) break;
        if(got2.size() == m) break;
        bool visited[m];
        fill(visited, visited+m, false);
        vector<pair<int, int>> toAsk;
        vector<pair<int, int>> tmp;
        for(int j = 0; j<m; j++){
            if(visited[j] || visited[norm(j+2, m)]) continue;
            if(got2.count({j, norm(j+2, m)})) continue;
            toAsk.push_back({good[j], good[norm(j+2, m)]});
            tmp.push_back({j, norm(j+2, m)});
            visited[j] = 1;
            visited[norm(j+2, m)] = 1;
            got2.insert({j, norm(j+2, m)});
        }
        string res = ask(toAsk);
        for(int j = 0; j<toAsk.size(); j++){
            next2[tmp[j].first] = res[j]-'0';
            prev2[tmp[j].second] = res[j]-'0';
        }
    }
    // cout << next2[0] << endl;
    int ans[n];
    fill(ans, ans+n, -1);
    ans[good[0]] = 0;
    ans[good[1]] = 1;
    for(int i = 2; i<m; i++){
        int p1 = ans[good[i-1]], p2 = ans[good[i-2]];
        if(prev2[i] == 1) ans[good[i]] = p2;
        else ans[good[i]] = 3-p1-p2;
    }
    // cout << ans[good[3]] << endl;
    for(int i = 0; i<m; i++){
        int j = norm(good[i]+1, n);
        while(ans[j] == -1){
            ans[j] = ans[good[i]];
            j = norm(j+1, n);
        }
    }
    // cout << ans[4] << endl;
    vector<int> colors[3];
    for(int i = 0; i<n; i++) colors[ans[i]].push_back(i);
    cout << "A " << colors[0].size() << " " << colors[1].size() << " " << colors[2].size() << endl;
    for(int j = 0; j<3; j++){
        for(auto x : colors[j]) cout << x+1 << " ";
        cout << endl;
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve(t);
    }
}
#include <bits/stdc++.h>
using namespace std;

bool check(vector <int> &nx, vector <int> &pv) {
    // check is this graph has only linear components.
    vector <bool> vis(26, false);
    queue <int> q;
    for(int i = 0; i < 26; i++) {
        if(pv[i] >= 0 && nx[pv[i]] != i) return false;
        if(nx[i] >= 0 && pv[nx[i]] != i) return false;
        if(pv[i] == -1) q.push(i);
    }
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        vis[curr] = true;
        int temp = nx[curr];
        while(temp != -1) {
            if(vis[temp]) return false;
            vis[temp] = true;
            temp = nx[temp];
        }
    }
    for(int i = 0; i < 26; i++) if(!vis[i]) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector <int> nx(26, -1), pv(26, -1);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if(pv[c] == -1) {
                cnt++;
                if(cnt == 26) {
                    for(int j = 0; j < 26; j++) {
                        if(nx[j] == -1) {
                            nx[j] = c;
                            pv[c] = j;
                        }
                    }
                    continue;
                }
                for(int j = 0; j < 26; j++) {
                    if(nx[j] == -1) {
                        nx[j] = c;
                        pv[c] = j;
                        if(check(nx, pv)) break;
                        nx[j] = -1;
                        pv[c] = -1;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            cout << (char)((int)('a') + pv[s[i] - 'a']);
        }
        cout << '\n';
    }
    
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

string s;
int w, n, pos[11][53][2];
map<vector<int>, pair<int, string> > m;
pair<int, string> dfs(vector<int> p) {
    if (m.count(p)) return m[p];
    pair<int, string> ans={0, ""};
    for (int k=1; k<=52; k++) {
        vector<int> uj;
        bool baj=0;
        for (int i=0; i<n; i++) {
            if (pos[i][k][0]>p[i]) uj.push_back(pos[i][k][0]);
            else if (pos[i][k][1]>p[i]) uj.push_back(pos[i][k][1]);
            else baj=1;
        }
        if (!baj) ans=max(ans, dfs(uj));
    }
    if (p[n-1]) {
        ans.first++;
        ans.second=s[p[n-1]-1]+ans.second;
    }
    m[p]=ans;
    return ans;
}
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> s;
            for (int j=0; j<s.size(); j++) {
                int x=(s[j]<='Z' ? s[j]-'A'+1 : s[j]-'a'+27);
                if (!pos[i][x][0]) pos[i][x][0]=j+1;
                else pos[i][x][1]=j+1;
            }
        }
        vector<int> p(n, 0);
        auto x=dfs(p);
        cout << x.first << "\n" << x.second << "\n";

        m.clear();
        memset(pos, 0, sizeof(pos));
    }
    return 0;
}
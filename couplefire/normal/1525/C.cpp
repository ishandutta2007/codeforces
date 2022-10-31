#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> coord(n), ans(n, -1), dir(n);
        for(int i = 0; i<n; i++) cin >> coord[i];
        for(int i = 0; i<n; i++){
            char c; cin >> c;
            if(c == 'L') dir[i] = -1;
            else dir[i] = 1;
        }
        vector<array<int, 3>> points[2];
        for(int i = 0; i<n; i++){
            points[coord[i]%2].push_back({coord[i], dir[i], i});
        }
        for(int t = 0; t<2; t++){
            sort(points[t].begin(), points[t].end());
            stack<array<int, 3>> st;
            for(int i = 0; i<points[t].size(); i++){
                if(st.empty() || points[t][i][1] == 1) st.push(points[t][i]);
                else{
                    auto p1 = st.top(), p2 = points[t][i]; st.pop();
                    ans[p1[2]] = ans[p2[2]] = (p2[0]-p1[1]*p1[0])/2;
                }
            }
            while(st.size()>=2){
                array<int, 3> p1 = st.top(); st.pop();
                array<int, 3> p2 = st.top(); st.pop();
                if(p2[1] == 1) ans[p1[2]] = ans[p2[2]] = ((m-p1[0])+(m-p2[0]))/2;
                else ans[p1[2]] = ans[p2[2]] = ((m-p1[0])+p2[0]+m)/2;
            }
        }
        for(int i = 0; i<n; i++) cout << ans[i] << " ";
        cout << endl;
    }
}
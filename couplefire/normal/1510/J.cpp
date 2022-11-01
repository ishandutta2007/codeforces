#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n;
string s;
vector<array<int, 2>> ranges;
int bad[2*N];

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s; n = s.length(); s = "$"+s;
    for(int i = 1; i<=n; i++){
        int l = i;
        while(i <= n && s[i]=='#') i++;
        if(i-1<l) continue;
        ranges.push_back({l, i-1});
    }
    if((int)ranges.size() == 0){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1; i<(int)ranges.size(); i++){
        int l = ranges[i][0], r = ranges[i][1];
        int pr = ranges[i-1][1];
        bad[0]++;
        bad[pr+n+2+1-l]--;
        bad[pr+n+2+1-l+1]++;
        bad[pr+n+5-l]--;
    }
    int fr = ranges.back()[1];
    bad[0]++; bad[fr+1]--;
    bad[fr+2]++; bad[fr+3]--;
    int fl = ranges.front()[0];
    bad[0]++; bad[n+2-fl]--;
    bad[n+2-fl+1]++; bad[n+2-fl+1+1]--;
    int curcnt = 0;
    for(int i = 0; i<=n+1; i++){
        curcnt += bad[i];
        if(curcnt) continue;
        vector<array<int, 2>> vals;
        for(int j = 0; j<(int)ranges.size(); j++){
            int l = ranges[j][0], r = ranges[j][1];
            vals.push_back({l+i-n-2, r+1});
        }
        // cout << vals.front()[1] << endl;
        vector<int> ans;
        int tmp = 0;
        while(tmp+2 <= vals[0][0])
            ans.push_back(tmp), tmp+=2;
        for(int j = 0; j<(int)vals.size(); j++){
            ans.push_back(vals[j][0]);
            ans.push_back(vals[j][1]);
            if(j == (int)vals.size()-1) continue;
            int cur = vals[j][1]+2;
            while(cur+2 <= vals[j+1][0])
                ans.push_back(cur), cur+=2;
        }
        tmp = ans.back()+2;
        while(tmp+2 <= i)
            ans.push_back(tmp), tmp+=2;
        ans.push_back(i);
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        cout << (int)ans.size()-1 << endl;
        for(int j = 1; j<(int)ans.size(); j++)
            cout << ans[j]-ans[j-1]-1 << " ";
        cout << endl;
        return 0;
    }
    cout << -1 << endl;
}
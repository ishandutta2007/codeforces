#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int extra = 0, cnt = 0;
        for(int i = 0; i<n; i++)
            if(s[i]=='1'&&s[n-1-i]=='0') extra++;
            else if(s[i]=='0'&&s[n-1-i]=='0') cnt++;
        if(cnt%2 && cnt>1){
            cout << "ALICE" << endl;
            continue;
        }
        int val = cnt-2*min(cnt/2+1, cnt)+extra;
        if(val>0) cout << "ALICE" << endl;
        else if(val==0) cout << "DRAW" << endl;
        else cout << "BOB" << endl;
    }
}
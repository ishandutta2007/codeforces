#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    string s[3]; cin >> s[0] >> s[1] >> s[2];
    int cnt[3][2];
    for(int i = 0; i<3; i++) cnt[i][0] = count(s[i].begin(), s[i].end(), '0'), cnt[i][1] = count(s[i].begin(), s[i].end(), '1');
    string a = "x", b = "x"; bool flipped = false;
    vector<int> bruh = {0, 1, 2};
    do{
        if(cnt[bruh[0]][0] >= n && cnt[bruh[1]][0] >= n){
            a = s[bruh[0]], b = s[bruh[1]];
            break;
        }
        if(cnt[bruh[0]][1] >= n && cnt[bruh[1]][1] >= n){
            a = s[bruh[0]], b = s[bruh[1]];
            for(int i = 0; i<2*n; i++){
                if(a[i] == '0') a[i] = '1';
                else a[i] = '0';
                if(b[i] == '0') b[i] = '1';
                else b[i] = '0';
            }
            flipped = 1;
            break;
        }
    } while(next_permutation(bruh.begin(), bruh.end()));
    a += "x", b += "x";
    string res = "";
    int cnta = 0, cntb = 0;
    while(cnta < 2*n || cntb < 2*n){
        if(a[cnta] == '1' || b[cntb] == '1'){
            res += '1';
            if(a[cnta] == '1') cnta++;
            if(b[cntb] == '1') cntb++;
        }
        else{
            res += '0';
            if(cnta < 2*n) cnta++; 
            if(cntb < 2*n) cntb++;
        }
    }
    if(flipped){
        for(int i = 0; i<res.length(); i++){
            if(res[i] == '0') res[i] = '1';
            else res[i] = '0';
        }
    }
    cout << res << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}
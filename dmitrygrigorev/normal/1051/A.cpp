#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    string s;
    cin >> s;
    string A = "qwertyuiopasdfghjklzxcvbnm";
    string B = "QWERTYUIOPASDFGHJKLZXCVBNM";
    string C = "1234567890";
    vector<int> val;
    for (int i=0; i < s.size(); i++){
        for (int j=0; j < 26; j++) if (A[j] == s[i]) val.push_back(0);
        for (int j=0; j < 26; j++) if (B[j] == s[i]) val.push_back(1);
        for (int j=0; j < 10; j++) if (C[j] == s[i]) val.push_back(2);
    }
    string AAA[3] = {A, B, C};
    vector<bool> has(3);
    fill(has.begin(), has.end(), false);
    for (int i=0; i < s.size();i++) has[val[i]] = true;
    int S = 0;
    for (int i=0;i<3;i++) S += has[i];
    if (S==3){
        cout << s << endl;
        return;
    }
    if (S==2){
        int a=0, b=0, c=0;
        for (int i=0; i < s.size(); i++){
            if (val[i] == 0) a++;
            if (val[i] == 1) b++;
            if (val[i] == 2) c++;
            if (max(a, max(b, c)) == 2){
                for (int j=0; j < 3; j++) if (!has[j]) {
                    s[i] = AAA[j][0];
                    cout << s << endl;
                    return;
                }
            }
        }
    }
    if (S==1){
        int ctr=0;
        for (int j=0; j < 3;j++){
            if (has[j]) continue;
            s[ctr] = AAA[j][0];
            ctr++;
        }
        cout << s << endl;
    }
}
signed main(){
    int t;
    cin >> t;
    for (int i=0;i<t;i++) solve();

}
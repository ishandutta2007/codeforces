#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> MOD = {1000000007, 1000000009, 998244353};
vector<int> PRIMES = {179, 231, 119};
int h[1000010][3];
int pw[1000010][3];
int K = 1000002;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    cin >> s >> t;
    int zr = 0, on = 0;
    for (int i=0; i < s.size(); i++){
        if (s[i] == '0') zr++;
        else on++;
    }
    for (int i=0;i<3;i++) pw[0][i] = 1;
    for (int i=1; i < 1000010; i++){
        for (int j=0; j < 3; j++) pw[i][j] = (pw[i-1][j] * PRIMES[j]) % MOD[j];
    }
    if (on > zr){
        swap(on, zr);
        for (int i=0;i<s.size();i++){
            if (s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }
    }
    //cout << s << endl;
    for (int i=0; i < 3; i++) h[0][i] = 0;
    for (int i=0; i < t.size(); i++){
        for (int j=0; j < 3; j++){
            h[i+1][j] = (h[i][j] + pw[i][j]*(t[i] - 'a' + 1)) % MOD[j];
        }
    }
    int z = 1;
    int ans = 0;
    int hz[3], ho[3];
    while (true){
        if (z*zr >= t.size()) break;
        int ost = t.size() - z*zr;
        if (ost % on != 0){
            z++;
            continue;
        }
        int o = ost/on;
        int u = 0;
        for (int i=0; i < 3; i++) hz[i] = -1;
        for (int i=0; i < 3; i++) ho[i] = -1;
        bool ab = true;
        for (int i=0; i < s.size(); i++){
            int L, R;
            if (s[i] == '0'){
                L = u, R = u+z-1;
                for (int j=0; j < 3; j++){
                    int H = (h[R+1][j] - h[L][j]) % MOD[j];
                    H *= pw[K-R][j];
                    H %= MOD[j];
                    if (H < 0) H += MOD[j];
                    //if (z == 1) cout << L << " " << R << " "<< H << endl;
                    if (hz[j] != -1 && hz[j] != H) ab = false;
                    hz[j] = H;
                }
                u += z;
            }
            else{
                L = u, R = u+o-1;
                for (int j=0; j < 3; j++){
                    int H = (h[R+1][j] - h[L][j]) % MOD[j];
                    H *= pw[K-R][j];
                    H %= MOD[j];
                    if (H < 0) H += MOD[j];
                    if (ho[j] != -1 && ho[j] != H) ab = false;
                    ho[j] = H;
                }
                u += o;
            }

        }
        if (ho[0] == hz[0] && ho[1] == hz[1] && ho[2] == hz[2]) ab = false;
        if (ab){
            ans++;
        }
        z++;
    }
    cout << ans;

}
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000003643
#define P 10

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int &a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}

int binpow(int a, int b) {
    a %= MOD;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = 1ll*res * a % MOD;
        a = 1ll*a * a % MOD;
        b >>= 1;
    }
    return res;
}

string s;
int n;
int phash[1000006];
int invpw[1000006];
int pw[1000006];

int getHash(int i, int j){
    return mul(sub(phash[i], phash[j+1]), invpw[n-1-j]);
}

bool check(int i, int j){
    if(j-i < 2) return false;
    if(i < 0) return false;
    if((j-1-i != 1 && s[i+1] == '0') || (s[j] == '0' && n-1-j != 0)) return false;
    if(add(getHash(0, i), getHash(i+1, j-1)) == getHash(j, n-1)) return 1;
    return 0;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.length();
    int cur = 0;
    phash[n] = 0;
    for(int i = n-1; i>=0; i--){
        phash[i] = add(phash[i+1], mul(binpow(10, n-1-i), s[i]-'0'));
        // cout << add(2, 2) << endl;
    }
    invpw[n] = binpow(10, MOD-1-n);
    for(int i = n-1; i>=0; i--) invpw[i] = mul(invpw[i+1], 10);
    pw[0] = 1;
    for(int i = 1; i<=n; i++) pw[i] = mul(pw[i-1], 10);
    // cout << mul(100, binpow(10, MOD-3)) << endl;
    // cout << getHash(0, 0) << endl;
    for(int i = n-1; i>=0; i--){
        int ch[6]; ch[0] = n-1-i; ch[1] = n-1-i+1; ch[2] = n-1-i-1; ch[3] = i-(n-1-i)-2; ch[4] = i-(n-1-i)-1; ch[5] = i-(n-1-i)-3;
        for(int j = 0; j<6; j++){
            if(check(ch[j], i)){
                for(int k = 0; k<=ch[j]; k++) cout << s[k];
                cout << "+";
                for(int k = ch[j]+1; k<=i-1; k++) cout << s[k];
                cout << "=";
                for(int k = i; k<=n-1; k++) cout << s[k];
                cout << endl;
                exit(0);
            }
        }
    }
}
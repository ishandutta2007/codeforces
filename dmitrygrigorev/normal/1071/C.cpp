#include <bits/stdc++.h>
using namespace std;
int dp[1<<15][16];
int Dp[1<<15][16];
struct Kek{int a; int b; int c;};
Kek a[1<<15][16];
Kek Ad[1<<15][16];
int M=15;
bool Solve(int i, int st){
    if (i==0){
        Dp[i][st] = 1;
        return true;
    }
    if (st==0){
        Dp[i][st] = 0;
        return 0;
    }
    if (Dp[i][st] != -1) return Dp[i][st];
    bool res = false;
    for (int f=0; f <= M-1; f++){
        for (int j=1; f+2*j <= M-1; j++){
            int A = f, B=f+j, C=f+2*j;
            int kek = i;
            kek ^= (1<<A);
            kek ^= (1<<B);
            kek ^= (1<<C);
            bool tt = res;
            res |= Solve(kek, st-1);
            if (res && !tt){
               // cout << A << " " << B << " " << C << endl;
                Ad[i][st] = {A, B, C};
            }
        }
        if (res) break;
    }
    Dp[i][st] = (int) res;
    return res;
}
bool solve(int i, int st){
    if (i<=7){
        dp[i][st] = 1;
        return true;
    }
    if (st==0){
        dp[i][st] = 0;
        return false;
    }
    if (dp[i][st] != -1) return dp[i][st];
    bool res = false;
    for (int f=0; f <= 14; f++){
        for (int j=1; f+2*j <= 14; j++){
            int A = f, B=f+j, C=f+2*j;
            int kek = i;
            kek ^= (1<<A);
            kek ^= (1<<B);
            kek ^= (1<<C);
            bool tt = res;
            res |= solve(kek, st-1);
            if (res && !tt){
                a[i][st] = {A, B, C};
            }
        }
        if (res) break;
    }
    dp[i][st] = (int) res;
    return res;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans = 0;
    int n;
    cin >> n;
    vector<int> v(n);
    M = min(M, n);
    for (int i=0; i < (1<<15); i++) for (int j=0; j < 16; j++) dp[i][j] = -1;
    for (int i=0; i < (1<<15); i++) for (int j=0; j < 16; j++) Dp[i][j] = -1;
    for (int i=(1<<15)-1; i >= 0; i--){
        solve(i,4);
    }
    for (int i=0; i < n; i++) cin >> v[i];
    int step = 0;
    vector<Kek> inp;
    while (step + 15 <= n){
        int A=0;
        for (int i=step+14; i >= step; i--){
            int kek = (1<<(step+14-i));
            A += kek * v[i];
        }
        int dd = 4;
        //cout << dp[A][4] << endl;
        while (A > 7){
            Kek res = a[A][dd];
            int aa = res.a, bb = res.b, cc = res.c;
            inp.push_back({step+14-aa, step+14-bb, step+14-cc});
            v[step+14-aa] ^= 1;
            v[step+14-bb] ^= 1;
            v[step+14-cc] ^= 1;
            A ^= (1<<aa);
            A ^= (1<<bb);
            A ^= (1<<cc);
            dd--;
        }
        step += 12;
    }
    if (step != 0 && step > n-15) step = n-15;
    for (int i=0; i < (1<<M); i++) Solve(i, 10);
    int A = 0;
    for (int i=step; i < n; i++){
        int kek = (1<<(i-step));
        A += v[i]*kek;
    }
    if (!Dp[A][10]){
        cout << "NO";
        return 0;
    }
    int dd = 10;
    while (A > 0){
        Kek res = Ad[A][dd];
        int aa = res.a, bb = res.b, cc = res.c;
        //cout << aa << " " << bb << " " << cc << endl;
        inp.push_back({aa+step, bb+step, cc+step});
        v[aa+step] ^= 1;
        v[bb+step] ^= 1;
        v[cc+step] ^= 1;
        A ^= (1<<aa);
        A ^= (1<<bb);
        A ^= (1<<cc);
        dd--;
    }
    cout << "YES" << endl;
    cout << inp.size() << endl;
    for (int i=0;i<inp.size(); i++) cout << inp[i].a+1 << " " << inp[i].b+1 << " " << inp[i].c+1 << endl;
    return 0;
}
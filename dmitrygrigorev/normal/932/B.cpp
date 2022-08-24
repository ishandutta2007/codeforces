#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
int pref[9][1000010], ans[1000010];
int get(int num){
    int A = 1;
    while (num != 0){
        int let = num%10;
        num/=10;
        if (let!=0) A*=let;
    }
    return A;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i=0; i < 9; i++) pref[i][0] = 0;
    for (int i=1; i <= 9; i++){
        for (int j=0; j < 9; j++){
            if (j+1==i) pref[j][i] = pref[j][i-1]+1;
            else pref[j][i] = pref[j][i-1];
        }
        ans[i] = i;
    }
    for (int i=10; i < 1000010; i++){
        int num = get(i);
        ans[i] = ans[num];
        num = ans[i];
        for (int j=0; j < 9; j++){
            if (j+1==num) pref[j][i] = pref[j][i-1]+1;
            else pref[j][i] = pref[j][i-1];
        }
    }
    int q;
    cin >> q;
    for (int i=0; i < q; i++){
        int L, R, K;
        cin >> L >> R >> K;
        cout << pref[K-1][R] - pref[K-1][L-1] << endl;
    }
}
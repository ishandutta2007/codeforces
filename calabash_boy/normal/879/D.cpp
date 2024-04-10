#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k,m;
int stk[100005][2];
int bak[100005][2];
vector<pair<int, int> > v;
int top = 0;
int main() {
    cin >> n >> k >> m;
    for(int i = 1;i <= n;i++) {
        int x;cin >> x;
        if(!top || stk[top][0] != x) {
            stk[++top][0] = x;
            stk[top][1] = 1;
        } else {
            stk[top][1]++;
        }
        if(stk[top][1] == k) stk[top--][1] -= k;
    }
    LL tot = 0;
    for(int i = 1;i <= top;i++) {
        tot += stk[i][1];
    }
    int b = 1, e = top;
    while(b < e && stk[b][0] == stk[e][0]) {
        if((stk[e][1] + stk[b][1]) % k == 0) {
            e--;b++;
        } else {
            stk[b][1] = (stk[b][1] + stk[e][1]) % k;
            stk[e][1] = 0;
            break;
        }
    }
    LL ans = 0;
    if(e > b) {
        for(int i = b;i <= e;i++) ans += stk[i][1];
        ans *= (m-1);
        ans += tot;
    } else if(e == b) {
        if(stk[b][1] * m % k == 0) ans = 0;
        else {
            ans = tot + stk[b][1] * (m-1);
            ans -= stk[b][1] * m - stk[b][1] * m % k;
        }
    }
    cout << ans << endl;
}
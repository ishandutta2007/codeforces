#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

void solve(){
    int n; scanf("%d", &n);
    vector<int> permu(n);
    for(int i = 0; i<n; i++) scanf("%d", &permu[i]), --permu[i];
    vector<bool> visited(n, 0);
    int ans = 0;
    int num1 = 0, num2 = 0, num4 = 0, num3 = 0;
    int res = 1;
    for(int i = 0; i<n; i++){
        int len = 0; int v = i;
        while(!visited[v]) visited[v] = 1, v = permu[v], len++;
        // if(len != 0) printf("%d ", len);
        while(len > 4) len -= 3, ans++, num3++;
        if(len == 1) num1++;
        if(len == 2) num2++;
        if(len == 4) num4++;
        if(len == 3) num3++;
    }
    while(n > 4) n -= 3, res = 1ll*res*3%MOD;
    res = 1ll*res*n%MOD;
    printf("%d ", res);
    if(num1 == 1 && num2 == 0 && num4 == 0) ans++;
    int good12 = min(num1, num2); ans += good12;
    num1 -= good12; num2 -= good12;
    int good24 = min(num2, num4); ans += good24*2;
    num2 -= good24; num4 -= good24;
    if(num2 != 0){
        while(num2 >= 3) num2 -= 3, ans += 3;
    }
    else{
        int pnum1 = num1, pnum4 = num4;
        while(num1 >= 2 && num4 >= 1) num1 -= 2, num4 -= 1, ans += 3;
        // cout << num1 << " " << num4 << endl;
        if(num4 == 0){
            while(num1 > 4) num1 -= 3, ans += 2;
            if(num1 == 4 && pnum4 >= 1) ans += 1;
            else if(num1 == 4) ans += 2;
            else if(num1 == 3) ans += 2;
            else if(num1 == 2) ans += 1;
            else if(num1 == 1 && pnum1 >= 2 && pnum4 >= 1) ans--;
        }
        else if(num1 == 0){
            while(num4 >= 3) num4 -= 3, ans += 5;
            if(num4 == 2) ans += 3;
        }
        else{
            while(num4 >= 3) num4 -= 3, ans += 5;
            if(num4 == 2) ans += 4;
            else if(num4 == 1) ans += 2;
            else if(num4 == 0) ans--;
        }
    }
    printf("%d\n", ans);
}

int main(){
    int t; scanf("%d", &t);
    while(t--) solve();
}
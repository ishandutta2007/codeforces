/*
    > Author : LiM_817
*/

#include <bits/stdc++.h>

using namespace std;

const int MaxN = 600 + 5;
struct BigIntegar {
    int a[MaxN];
    int div , sum;
    BigIntegar() {
        memset(a , 0 , sizeof(a));
        a[0] = 0;
        div = sum = 0;
    }
};

int d , s;

bool vis[500 + 10][5000 + 10];

void outp(BigIntegar x) {
    for(int i = 1; i <= x . a[0] ; i++) cout << x . a[i];
    return ;
}
void BFS() {
    queue <BigIntegar> q;
    BigIntegar cur;
    q . push(cur);
    while(!q . empty()) {
        BigIntegar x = q . front(); q . pop();
        for(int i = 0; i < 10 ; i++) {
            BigIntegar t = x;
            t . a[0]++;
            t . a[t . a[0]] = i;
            t . div = (t . div * 10 + i) % d;
            t . sum += i;
            if(t . sum > s || vis[t . div][t . sum]) continue;
            vis[t . div][t . sum] = 1;
            if(t . div == 0 && t . sum == s) {
                outp(t);
                return; 
            }
            q . push(t);
        }
    }
    cout << -1 << endl;
    return ;
}
int main() {
    cin >> d >> s;
    BFS();
    return 0;
}
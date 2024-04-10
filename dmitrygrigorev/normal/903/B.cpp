#include <bits/stdc++.h>
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h1, a1, c1, h2, a2;
    cin >> h1 >> a1 >> c1 >> h2 >> a2;
    int op = h2 / a1;
    if (h2 % a1 != 0) op++;
    int dead = (op-1) * a2;
    int p = c1 - a2;
    int var = -1;
    for (int i=0; i < 10000; i++){
        int x = h1 + p*i;
        if (x > dead){
            var = i;
            break;
        }
    }
    cout << var+op << endl;
    for (int i=0; i < var; i++) cout << "HEAL" << endl;
    for (int i=0; i < op; i++) cout << "STRIKE" << endl;
    return 0;
}
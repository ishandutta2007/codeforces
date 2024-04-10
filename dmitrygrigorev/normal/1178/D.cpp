#include<bits/stdc++.h>
using namespace std;
#define int long long
bool sost[2000];
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=2; i < 2000; i++){
        if (sost[i]) continue;
        for (int j=i+i; j < 2000; j += i) sost[j] = true;
    }
    int n;
    cin >> n;
    int E = n;
    while (sost[E]) E++;
    cout << E << endl;
    for (int i=0; i < n; i++){
        cout << i+1 << " " << ((i+1)%n)+1 << endl;
    }
    for (int j=0; j < E-n; j++){
        cout << j+1 << " " << j+n/2+1 << endl;
    }
}
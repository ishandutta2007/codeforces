#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int x, h, m;
    cin >> x >> h >> m;
    for (int i=0; i < 100000; i++){
        //cout << h << " " << m << endl;
        if (h % 10 == 7 || m % 10 == 7){
            cout << i << endl;
            return 0;
        }
        m -= x;
        if (m < 0){
            m += 60;
            h --;
            if (h < 0) h = 23;
        }
    }
    return 0;
}
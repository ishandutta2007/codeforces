#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    int d=1;
    while(n){
        n--;
        if(d%m==0){
            n++;
        }
        d++;
    }
    cout << d-1;
    return 0;
}
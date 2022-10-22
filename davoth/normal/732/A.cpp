#include <bits/stdc++.h>
using namespace std;

int main() {
    int k,r,a;
    cin >> k >> r;
    for(int i=1; i<=10; i++){
        a=i;
        if(i*k%10==r || i*k%10==0) break;
    }
    cout << a;
    return 0;
}
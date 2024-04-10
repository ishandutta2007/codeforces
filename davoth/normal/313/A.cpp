#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    cin >> a;
    if(a>=0){
        cout << a;
        return 0;
    }
    if(a%10>a/10%10){
        cout << a/100*10+a%10;
    }else cout << a/10;
    return 0;
}
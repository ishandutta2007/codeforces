#include <bits/stdc++.h>
using namespace std;

bool d(int a){
    for(int i=3; ; i++){
        if(180.0*(i-2)/i==a) return true;
        else if(180.0*(i-2)/i>a) return false;
    }
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        if(d(temp)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
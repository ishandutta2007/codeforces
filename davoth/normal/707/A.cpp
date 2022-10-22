#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n*m; i++){
        char temp;
        cin >> temp;
        if(temp=='C' || temp=='M' || temp=='Y'){
            cout << "#Color";
            return 0;
        }
    }
    cout << "#Black&White";
    return 0;
}
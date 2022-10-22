#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n,k;
    cin >> n >> k;
    if(n>k*(k-1)){
        cout << "No";
        return 0;
    }
    cout << "Yes\n";
    for(int i=0; i<k-1; i++){
        for(int j=i+1; j<k; j++){
            cout << i+1 << ' ' << j+1 << '\n';
            n--;
            if(n<1) return 0;
            cout << j+1 << ' ' << i+1 << '\n';
            n--;
            if(n<1) return 0;
        }
    }
    return 0;
}
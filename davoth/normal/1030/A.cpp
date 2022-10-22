#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,r=0;
    cin >> n;
    while(n--){
        int temp;
        cin >> temp;
        r=max(r,temp);
    }
    if(r) cout << "HARD";
    else cout << "EASY";
    return 0;
}
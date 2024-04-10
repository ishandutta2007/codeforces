#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, cnt=0;
    cin >> n >> k;
    while(n--){
        int temp;
        cin >> temp;
        if(5-temp>=k) cnt++;
    }
    cout << cnt/3;
    return 0;
}
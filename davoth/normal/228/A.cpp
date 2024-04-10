#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[4],cnt=0;
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    for(int i=1; i<4; i++){
        for(int j=0; j<i; j++){
            if(a[i]==a[j]){
                cnt++;
                break;
            }
        }
    }
    cout << cnt;
    return 0;
}
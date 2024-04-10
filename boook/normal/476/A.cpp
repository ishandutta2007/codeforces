#include <bits/stdc++.h>
using namespace std;
int n , m , half;
int main(){
    cin >> n >> m;
    if(n % 2 == 0) half = n / 2;
    if(n % 2 == 1) half = n / 2 + 1;
    int ans = -1;
    for(int i = half ; i <= n ; i ++){
        if(i % m == 0){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
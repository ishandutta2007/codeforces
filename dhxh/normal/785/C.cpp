#include <iostream>
#include <cmath>

using namespace std;

long long m, n;
long long ans;

int main() {
    int i, j;
    long long l, r;
    long long mid;
    
    cin >> n >> m;
    
    if(n <= m){
        ans = n;
    }else{
        ans = m;
        l = 1;
        r = 2e9;
        
        while(l < r){
            mid = (l + r) / 2;
            if(mid * (mid + 1) / 2 + m < n){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        ans += l;
    }
    
    cout << ans << endl;
    
    return 0;
}
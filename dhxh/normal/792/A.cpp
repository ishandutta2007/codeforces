#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long long m, n;
long long ans = 2000000007, cnt;

int a[200005];

int main() {
    int i, j;
    long long l, r;
    long long mid;
    
    cin >> n;
    
    for(i=1;i<=n;i++){
        cin >> a[i];
    }
    
    sort(a + 1, a + n + 1);
    
    for(i=1;i<n;i++){
        if(a[i + 1] - a[i] < ans){
            ans = a[i + 1] - a[i];
            cnt = 1;
        }else if(a[i + 1] - a[i] == ans){
            cnt++;
        }
    }
    
    cout << ans << " " << cnt << endl;
    
    return 0;
}
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
    int n, last = 0, x, h = 0;
    scanf("%d", &n);
    long long int ans = 2*n - 1;
    while(n--){
        scanf("%d", &x);
        if(last > x){
            ans += last -x;
            h = x;
        }
        if(h < x){
            ans += x - h;
            h = x;
        }
        last = x;
    }
    cout << ans << endl;
    return 0;
}
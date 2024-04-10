#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    int t[8]={1,3,15,133,2025,37851,1030367,36362925}, n;
    scanf("%d", &n);
    if((n&1)==0){
        puts("0"); return 0;
    }
    long long ans=1, mod = 1000000007;
    for(int i = 2; i <= n; ++i)
        ans = (ans*i)%mod;
    ans = (ans*t[n/2])%mod;

    cout << ans << endl;
    return 0;
}
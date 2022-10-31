#include <bits/stdc++.h>
using namespace std;
long long n, k;

long long checkodd(long long num){
    if(num > n) return 0;
    long long num1 = num, num2 = num;
    long long sum = 0;
    while(num2 <= n){
        sum += num2-num1+1;
        num1 *= 2;
        num2 *= 2;
        ++num2;
    }
    sum += max(0ll, n-num1+1);
    return sum;
}

long long checkeven(long long num){
    return checkodd(num)+checkodd(num+1);
}

int main(){
    //freopen("a.in", "r", stdin);
    cin >> n >> k;
    if(n == k){
        cout << 1 << endl;
        exit(0);
    }
    long long lo = 0, hi = (n-1)/2;
    while(lo < hi){
        long long mid = lo+(hi-lo+1)/2;
        if(checkodd(mid*2+1) < k) hi = mid-1;
        else lo = mid;
    }
    long long ans = 2*lo+1;
    lo = 1, hi = n/2;
    while(lo < hi){
        long long mid = lo+(hi-lo+1)/2;
        if(checkeven(mid*2) < k) hi = mid-1;
        else lo = mid;
    }
    ans = max(ans, 2*lo);
    cout << ans << endl;
}
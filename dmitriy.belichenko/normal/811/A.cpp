#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;
long long  arr[1005][1005];
long long  cnt = 0;
static long parsenum(long j, long l) {
    string k = "";
    long cur = 0;
    for (int i = (int) j; i <= l; ++i) {
        cur *= 10;
        cur += k[i] - '0';
    }
    return cur;
}

static long gcd(long a, long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

static bool pri(int k) {
    if (k == 1) return false;
    for (int i = 2; i * i <= k; i++) {
        
        if (k % i == 0) return false;
    }
    return true;
}


int main()
{
    int a, b;
    cin>>a>>b;
    int vla = sqrt(a);
    if(vla*(vla+1) > b) cout<<"Valera";
    else cout<<"Vladik";
}
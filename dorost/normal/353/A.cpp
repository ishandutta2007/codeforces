/*  * In the name of GOD 
    * Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N], b[N];

int32_t main(){
    int n;
    cin >> n;
    bool f = false;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        sum1 += a[i];
        sum2 += b[i];
        if (a[i] % 2 != b[i] % 2)
            f = true;
    }
    if ((sum1 + sum2) % 2 == 0 && sum1 % 2 == 0){
        cout << 0;
    }else if((sum1 + sum2) % 2 == 0){
        cout << (f ? 1 : -1);   
    }else{
        cout << -1;
    }
}
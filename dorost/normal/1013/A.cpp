#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
    cin >> n;
    int a[n], x, sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum1 += a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> x;
        sum2 += x;
    }
    cout << (sum1 >= sum2 ? "Yes" : "No");
}
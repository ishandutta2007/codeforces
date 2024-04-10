#include <bits/stdc++.h>

using namespace std;

int A[500000];

int main() {
    int n, buzz;
    cin>>n>>buzz;
    for(int i=1; i<=n; i++) {
        cin>>A[i];
    }
    sort(A+1, A+n+1);

    int sum = 0;
    for(int i=n; i>=1; i--) {
        sum += A[i];
        if(sum >= buzz) {
            cout << n-i+1;
            return 0;
        }
    }

    return 0;
}
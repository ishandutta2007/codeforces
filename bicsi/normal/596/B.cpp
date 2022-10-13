#include <bits/stdc++.h>

using namespace std;

int A[500000];

int main() {
    int n;
    cin>>n;

    int64_t total = 0;
    for(int i=1; i<=n; i++) {
        cin>>A[i];
        total += abs(A[i] - A[i-1]);
    }
    cout<<total;
}
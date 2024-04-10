#include <bits/stdc++.h>

using namespace std;

int A[500000];

int main() {

    int n;
    cin>>n;


    long long sum = 0;
    for(int i=1; i<=n; i++) {
        cin>>A[i];
        sum += A[i];
    }

    sort(A+1, A+n+1);

    int med = sum / n;
    int nomed = n - sum % n;

    long long total = 0;
    for(int i=1; i<=n; i++) {
        if(A[i] <= med) total += med - A[i];
        if(--nomed == 0) med++;
    }

    cout << total;

    return 0;
}
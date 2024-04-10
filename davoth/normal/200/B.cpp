#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    float sum=0;
    cin >> n;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        sum+=temp;
    }
    cout << setprecision(7) << sum/n;
    return 0;
}
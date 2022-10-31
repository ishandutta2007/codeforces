#include <bits/stdc++.h>
using namespace std;

int n, a[100010];
int main() {
    cin >> n;
    int mi = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if(i>0 && a[i-1]>a[i]) mi = i;
    }

    for(int i = 0; i < n-1; ++i)
        if(a[(i+mi)%n] > a[(i+mi+1)%n]) {
            puts("-1");
            return 0;
        }
    cout << (n - mi)%n << endl;


    return 0;
}
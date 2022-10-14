#include <iostream>
#include <algorithm>
using namespace std;

int h[100005];
int main() {
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        int v; cin >> v;
        h[v]++;
    }
    //gprime();
    int mx = 1;
    for(int gcd=2; gcd<=100000; gcd++) {
        int sum = 0;
        for(int i=1; gcd*i<=100000; i++) sum += h[i*gcd];
        mx = max(mx, sum);
    }
    cout << mx << endl;
}
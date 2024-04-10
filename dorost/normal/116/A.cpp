#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, a, b, maxi = 0, w = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        w += (b - a);
        if (w > maxi){
            maxi = w;
        }
    }
    cout << maxi;
}
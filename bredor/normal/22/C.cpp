//  228

#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>

#define MOD 1000000007
typedef long long ll;

using namespace std;

int main() {
    int n, m, v;
    cin >> n >> m >> v;
    int arr[n+1];
    
    if (m < n-1 || m > ((n-1)*(n-2))/2 + 1) {
        cout << -1 << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            arr[i] = i;
        }
        
        arr[v] = 1;
        arr[1] = v;
        
        for (int i = 2; i <= n; i++) {
            cout << v << " " << arr[i] << endl;
        }
        
        int printed = n-1;
        
        if (printed < m) {
            for (int i = 2; i < n; i++) {
                for (int j = i+1; j < n; j++) {
                    cout << arr[i] << " " << arr[j] << endl;
                    printed += 1;
                    
                    if (printed == m) break;
                }
                
                if (printed == m) break;
            }
        }
    }
    
    return 0;
}
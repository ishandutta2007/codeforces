#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin>>t;
    
    while(t--) {
        int n;
        cin >> n;
    	int a[n + 1];
    	int sp = (n + 1) / 2;
    	a[0] = sp + 1;
    	for (int i = 1; i < sp; i++) { 
    	    a[i] = i;
    	}
    	for (int i = sp; i < n - 1; i++) {
    	    a[i] = i + 2;
    	}
    	
    	a[n - 1] = sp;
    	long long ans = 1LL * (n - 1) * (n - 1);
    	for (long long i = sp; i < n - 1; i++) {
    	    ans += i * i * 1LL;
    	}
    	for (long long i = 1; i < sp; i++) {
    	    ans += (n - i - 1) * (n - i - 1) * 1LL;
    	}
    	cout << ans << '\n';
    	for (int i = 0; i < n; i++) {
    	    cout << a[i] << " ";
    	}
    	
    	cout << '\n';
    	cout << n - 1 << '\n';
    	for (int i = sp - 1; i > 0; i--) {
    	    cout << i + 1 << " " << n << '\n';    
    	}
        for (int i = sp; i < n - 1; i++) {
            cout << i + 1 << " " << 1 << '\n';
    	}
    	cout << 1 << " " << n << '\n';
    }
}
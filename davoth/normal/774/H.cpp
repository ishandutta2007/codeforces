#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    string s;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >>a[i];
    }
    int c=0;
    for(int i=n-1; i>=0; i--){
        while(a[i]) {
            if (c == 0) {
                for (int j = 0; j < i + 1; j++) {
                    s.push_back('a');
                }
                for (int j = 0; j <= i; j++) {
                    a[j] -= i + 1 - j;
                }
                c = 1;
            } else{
                for (int j = 0; j < i + 1; j++) {
                    s.push_back('b');
                }
                for (int j = 0; j <= i; j++) {
                    a[j] -= i + 1 - j;
                }
                c = 0;
            }
        }
    }
    cout << s;
    return 0;
}
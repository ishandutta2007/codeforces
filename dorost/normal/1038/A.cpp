#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, k;
    string s;
    cin >> n >> k >> s;
    int a[k] = {};
    for (int i = 0; i < n; i++){
        a[s[i] - 'A']++;
    }
    int min = a[0];
    for (int i = 1; i < k; i++){
        if (a[i] < min){
            min = a[i];
        }
    }
    cout << min * k;
}
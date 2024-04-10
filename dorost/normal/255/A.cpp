#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, x, a[3] = {};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (i % 3 == 0) {
            a[0] += x;
        }else if (i % 3 == 1) {
            a[1] += x;
        }else {
            a[2] += x;
        }
    }
    int maxi = a[0], winner = 1;
    for (int i = 1; i < 3; i++) {
        if(a[i] > maxi){
            maxi = a[i];
            winner = i + 1;
        }
    }
    if (winner == 1){
        cout << "chest";
    }else if(winner == 2) {
        cout << "biceps";
    }else {
        cout << "back";
    }
}
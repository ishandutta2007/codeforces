#include<bits/stdc++.h>
using namespace std;

bool checkprime(int n){
    for (int i = 2; 1LL * i * i <= n; i++) if (n % i == 0) return false;
    return true;
}

int n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    if (checkprime(n)) return cout << 1, 0;
    if (n % 2 == 0) return cout << 2, 0;
    if (checkprime(n-2)) return cout << 2, 0;
    cout << 3;
}
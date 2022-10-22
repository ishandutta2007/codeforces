#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool is_even(int x){
    for (int i = 2; i * i <= x; i++){
        if(x % i == 0)
            return false;
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++){
        if (!is_even(i)){
            if (!is_even(n - i)){
                cout << i << ' ' << n - i << endl;
                break;
            }
        }
    }
}
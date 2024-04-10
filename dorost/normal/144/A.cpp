#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool is_eval(int x){
    for (int i = 2; i * i <= x; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    int a[n], max = 0, min = 1e2 + 1, x = 0, y = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] > max){
            max = a[i];
            x = i;
        }
        if (a[i] <= min){
            min = a[i];
            y = i;
        }
    }
    if (x > y){
        cout << x + n - y - 2;
    }else
        cout << x + n - y - 1;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, max = 0, x, y;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        if(x + y > max){
            max = x + y;
        }
    }
    cout << max;
}
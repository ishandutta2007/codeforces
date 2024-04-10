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
    int n, m;
    cin >> n >> m;
    for(int x = n + 1; true; x++){
        if (is_eval(x)){
            if (m == x){
                cout << "YES";
            }else{
                cout << "NO";
            }
        break;
        }
    }
}
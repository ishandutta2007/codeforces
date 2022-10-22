#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n ,m;
    cin >> n >> m;
    int a = 0, b = 0, c = 0, d = 0;
    ll x;
    while(n --){
        cin >> x;
        if(x % 2){
            a++;
        }else{
            b++;
        }
    }
    while(m --){
        cin >> x;
        if(x % 2){
            c++;
        }else{
            d++;
        }
    }
    cout << min(a, d) + min(b , c);
}
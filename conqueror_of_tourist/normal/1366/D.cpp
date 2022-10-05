#include <iostream>
using namespace std;
 
typedef long long ll;

int BIG = 10000010;


int main() {
    bool primes[10000010];
    ll div[10000010];

    
    for (int i = 2; i < BIG; i++){
        primes[i] = true;
    }
    
    for (int i = 2; i < BIG; i++){
        if (primes[i]){
            for (int j = i; j < BIG; j += i){
                primes[j] = false;
                div[j] = i;
            }
        }
    }
    
    ll n;
    cin >> n;
    
    ll v;
    
    ll out1[n];
    ll out2[n];
    for (int i = 0; i < n; i++){
        cin >> v;
        
        ll pdiv = div[v];
        while (v % pdiv == 0){
            v /= pdiv;
        }
        
        if (v > 1){
            out1[i] = pdiv;
            out2[i] = v;
        }
        
        else{
            out1[i] = -1;
            out2[i] = -1;
        }
    }
    
    for (int i = 0; i < n; i++){
        cout << out1[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++){
        cout << out2[i] << " ";
    }
    
    return 0;
}
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n % 2 == 1){
        cout << "-1" << endl;
    }
    else{
        for(int k = 1; k <= n; k++){
            if(k > 1) cout << ' ';
            if(k%2==1) cout << k+1;
            else cout << k-1;
        }
        cout << endl;
    }
    return 0;
}
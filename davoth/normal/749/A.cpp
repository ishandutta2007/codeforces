#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k=0,c=0;
    cin >> n;
    if(n==2){
        cout << 1 << '\n' << 2;
        return 0;
    }else{
        if(n%2==1) {
            n -= 3;
            k++;
            c = 1;
        }
        k+=n/2;
    }
    cout << k << '\n';
    if(c){
        cout << 3 << ' ';
        k--;
    }
    for(int i=0; i<k; i++){
        cout << 2 << ' ';
    }
    return 0;
}
#include <iostream>
#include <cstdio>
#define ll unsigned long long
using namespace std;

int main(){
    int T;
    cin >> T;
    while (T --){
        long long a, b;
        cin >> a >> b;
        if (a - b == 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n <= 2) cout << -1 << endl;
    else{
        cout << 2 << ' ' << 3 << ' ' << 1;
        for(int i = 4; i <= n; i++)
            cout << ' ' << i;
        cout << endl;
    }
    return 0;
}
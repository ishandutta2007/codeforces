#include <bits/stdc++.h>
using namespace std;

int n , m;
int main(){
    cin >> n >> m;
    cout << m * (6 * (n - 1) + 5) << endl;
    for(int i = 0 ; i < n ; i ++){
        for(int j : {1 , 3 , 4 , 5})
            cout << m * (6 * i + j) << " ";
        cout << endl;
    }
    return 0;
}
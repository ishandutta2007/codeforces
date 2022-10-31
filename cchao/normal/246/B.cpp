#include <iostream>
using namespace std;

int main(){
    int n, tmp, sum = 0;
    cin >> n;
    for(int i =0 ; i < n; i++)  {
        cin >> tmp;
        sum += tmp;
    }
    if(sum % n == 0) cout << n << endl;
    else cout << n-1 << endl;

    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    for(int i=0;i<100000;i++){
        if(a * 10 / b == c) {
            cout << i + 1 << endl;
            break;
        } else if(i == 99999) cout << -1 << endl;
        a = 10 * a % b;
    }
}
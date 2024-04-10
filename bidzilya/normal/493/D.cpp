#include <iostream>
using namespace std;


int main()
{
    int n;
    cin >> n;
    
    if (n % 2 == 0) {
        cout << "white" << endl;
        cout << 1 << " " << 2 << endl;
    } else {
        cout << "black" << endl;
    }

    return 0;
}
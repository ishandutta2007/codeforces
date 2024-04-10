#include <iostream>
using namespace std;

int main(){
    int x;
    cin >> x;

    if( x == 3 ){
        cout << "5\n";
    }
    else{
        int m = 0;
        while( m*m + (m+1)*(m+1) < x ) ++m;

        cout << 2*m+1 << endl;
    }
}
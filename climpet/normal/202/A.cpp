#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;
    
    char m = 0;
    for( int i = 0; i < s.size(); ++i )
        m = max( m, s[i] );
    for( int i = 0; i < s.size(); ++i )
        if( m == s[i] )
            cout << m;
    cout << endl;
}
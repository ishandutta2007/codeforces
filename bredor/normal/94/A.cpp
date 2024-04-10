//  228

/*
 *  
 * 
 *     
 */

#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main() {
    string password;
    cin >> password;

    array <string, 10> digits;
    for (auto &digit : digits)
        cin >> digit;

    for (int i = 0; i < 80; i += 10) {
        int digit = find(begin(digits), end(digits), password.substr(i, 10)) - begin(digits);
        cout << digit;
    }

    return 0;
}
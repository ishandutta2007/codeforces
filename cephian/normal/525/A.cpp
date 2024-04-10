#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int n;
    string str;
    cin >> n >> str;
    
    int key[26];
    fill(key, key+26, 0);
    int buy = 0;
    for(int i = 0; i < str.length(); i += 2) {
        ++key[str[i] - 'a'];
        if(key[str[i+1] - 'A'] == 0) {
            ++buy;
        } else {
            --key[str[i+1] - 'A'];
        }
    }
    
    cout << buy << "\n";
    
}
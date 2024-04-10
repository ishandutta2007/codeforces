#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;

    if(n == 1)
        cout << "1\n1\n";
    else if(n == 2)
        cout << "1\n1\n";
    else if(n == 3)
        cout << "2\n1 3\n";
    
    if(n < 4)
        return 0;
    vector<int> v;
    for(int i = (n+1)/2; i > 0; --i) {
        v.push_back(i);
        if(n % 2 == 0 || i != 1)
            v.push_back(i + n/2);
    }
    cout << n << "\n";
    for(int i = 0; i < v.size(); ++i)
        cout << v[i] << ((i == v.size() - 1)? "\n" : " ");
    
    return 0;
}
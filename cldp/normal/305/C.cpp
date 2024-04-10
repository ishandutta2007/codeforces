#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;

const int MAXN = 1100;
const int INF = 1000000000;

map<int, int> hash;

int main() {
    int n;
    cin >> n;
    int a, b = 0, c = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        ++hash[a];
    }
    
    map<int, int>::iterator iter = hash.begin();
    while (iter != hash.end()) {
        //cout << "B: "<< iter->first << " " << iter->second << endl;
        if (iter->second > 1)
            hash[iter->first + 1] += iter->second / 2;
        iter->second %= 2;
        if (iter->second == 1) ++b;
        c = iter->first;
        //cout << "E: "<< iter->first << " " << iter->second << endl;
        ++iter;
    }
    
    cout << c + 1 - b << endl;

    return 0;
}
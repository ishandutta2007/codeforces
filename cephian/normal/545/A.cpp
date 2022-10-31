#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> good;
    for(int i = 0; i < n; ++i) {
        bool ok = true;
        for(int j = 0; j < n; ++j) {
            int t;
            cin >> t;
            if(t == 1 || t == 3)
                ok = false;
        }
        if(ok)
            good.push_back(i+1);
    }
    cout << good.size() << "\n";
    for(int i = 0; i < good.size(); ++i)
        cout << good[i] << ((i == good.size()-1)?"\n":" ");
    
}
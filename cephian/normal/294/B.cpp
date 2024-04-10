#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> t1, t2;
int n;

int main() {
    cin >> n;
    
    for(int i = 0; i < n; ++i) {
        int t, w;
        cin >> t >> w;
        if(t == 1) t1.push_back(w);
        else t2.push_back(w);
    }
    sort(t1.rbegin(), t1.rend());
    sort(t2.rbegin(), t2.rend());
    
    for(int len = 1; len <= 2*n; ++len) {
        for(int a2 = 0; a2*2 <= len && a2 <= t2.size(); ++a2) {
            if(len - 2*a2 > t1.size()) continue;
            int toplen = 0;
            for(int i = a2; i < t2.size(); ++i)
                toplen += t2[i];
            for(int j = len-2*a2; j < t1.size(); ++j)
                toplen += t1[j];
            if(toplen <= len) {
                cout << len << "\n";
                return 0;
            }
        }
    }
}
#include <iostream>
#include <vector>

using namespace std;

int n, s, sell[100001], buy[100001];
vector<int> vector2;

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        char x;
        int a, b;
        cin >> x >> a >> b;
        if (x == 'B') {
            buy[a] += b;
        } else {
            sell[a] += b;
        }
    }
    int count1 = 0, count2 = 0;
    
    for (int i = 0; i <= 100000; ++i) {
        if (sell[i] > 0) {
            vector2.push_back(i);
            count1++;
        }
        
        if (count1 == s) {
            break;
        }
    }
    
    for (int i = vector2.size()-1; i >= 0; --i) {
        cout << 'S' << " " << vector2[i] << " " << sell[vector2[i]] << endl;
    }
    
    for (int i = 100000; i >= 0; --i) {
        if (buy[i] > 0) {
            cout << 'B' << " " << i << " " << buy[i] << endl;
            count2++;
        }
        if (count2 == s) {
            break;
        }
    }
}
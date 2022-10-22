#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000007;
const int MAXN = 1010;


int main() {
    ios_base::sync_with_stdio(false);
    string P;
    int N, A = 0, B = 0;
    cin >> N >> P;
    for (int i = 0; i < N; ++i) {
        if (P[i] == 'A') ++A; else ++B;
    }
    if (A > B) {
        cout << "Anton" << endl;
    } else 
    if (B > A) {
        cout << "Danik" << endl;
        
    } else {
        cout << "Friendship" << endl;
    }
    
    
    return 0;
}
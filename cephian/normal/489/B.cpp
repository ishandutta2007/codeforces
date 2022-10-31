#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, m;
int boys[105];
int girls[105];

int main() {
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> boys[i];
    cin >> m;
    for(int i = 0; i < m; ++i)
        cin >> girls[i];
    sort(boys, boys+n);
    sort(girls, girls+m);
    
    int a = 0, b = 0;
    int pairs = 0;
    while(a < n && b < m) {
        int dist = boys[a] - girls[b];
        if(abs(dist) < 1.5) {
            ++pairs;
            ++a;
            ++b;
        } else if(boys[a] < girls[b])
            ++a;
        else ++b;
        
    }
    cout << pairs << "\n";
    return 0;
}
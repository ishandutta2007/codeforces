#include <iostream>
#include <set>
using namespace std;

int color[100005];
multiset<int> co;

int main() {
    int n; cin >> n;
    int ans = 0;
    for(int i=1; i<=n; i++) {
        int col; cin >> col;
        int prev = color[col];
        color[col]++;
        if(prev == 0) co.insert(1);
        else {
            co.erase(co.find(prev));
            co.insert(prev+1);
        }
        if(co.size() == 1) { ans = i; continue; }
        auto it = co.begin();
        if((*co.begin() == 1) && (*(++co.begin()) == *(--co.end()))) ans = i;
        if((*co.begin() == *(----co.end())) && (*(--co.end()) == *co.begin()+1)) ans = i;
    }
    cout << ans << endl;
}
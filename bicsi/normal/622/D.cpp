#include <iostream>
#include <queue>

using namespace std;

deque<int> Q1, Q2;

int main() {
    int n;
    cin >> n;
    Q2.push_back(n);
    for(int i=n-1; i > 0; i-=2) {
        Q1.push_back(i);
        Q1.push_front(i);

        if(i - 1 > 0) {
            Q2.push_back(i-1);
            Q2.push_front(i-1);
        }
    }
    Q2.push_back(n);

    for(auto x : Q1) cout << x << " ";
    for(auto x : Q2) cout << x << " ";

    return 0;
}
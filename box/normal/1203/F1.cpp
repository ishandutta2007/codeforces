#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct task {
    int price, profit;
};

vector<task> Pos, Neg;

int main() {
    int n, rating;
    cin >> n >> rating;
    for(int i=0; i<n; i++) {
        int pri, pro; cin >> pri >> pro;
        pri = max(pri, -pro);
        if(pro < 0) Neg.push_back({pri, pro});
        else Pos.push_back({pri, pro});
    }
    sort(Pos.begin(), Pos.end(), [](const task a, const task b) {
        return a.price < b.price;
    });
    sort(Neg.begin(), Neg.end(), [](const task a, const task b) {
        return a.price+a.profit > b.price+b.profit;
    });
    bool fahked = false;
    for(const task& t: Pos) {
        if(rating < t.price) { 
            fahked = true;
            break;
        }
        rating += t.profit;
    }
    if(!fahked) {
        for(const task& t: Neg) {
            if(rating < t.price) {
                fahked = true;
                break;
            }
            rating += t.profit;
        }
    }
    if(fahked) cout << "NO" << endl;
    else cout << "YES" << endl;
}
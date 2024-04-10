#include <iostream>
#include <vector>
using namespace std;

class BTN {
public:
    BTN* zeroch;
    BTN* onech;
    int depth, stsize; // here, the higher depth is, the shallower the node is, ex. depth=31 represents root and depth=0 represents leaf
    BTN(int dep) : depth(dep) {
        zeroch = nullptr;
        onech = nullptr;
        stsize = 0;
    }
    void insert(int n) {
        stsize += 1;
        if(depth == -1) return;
        if(n&(1<<depth)) {
            if(onech == nullptr) onech = new BTN(depth-1);
            onech->insert(n);
        } else {
            if(zeroch == nullptr) zeroch = new BTN(depth-1);
            zeroch->insert(n);
        }
    }
    void remove(int n) {
        stsize -= 1;
        if(depth == -1) return;
        if(n&(1<<depth)) onech->remove(n);
        else zeroch->remove(n);
    }
    int lowestXOR(int q) {
        if(depth == -1) return 0;
        if((zeroch == nullptr || zeroch->stsize == 0) && (onech == nullptr || onech->stsize == 0)) {
            cout << "OH STREWTH IMMA IGHT OUT" << endl;
            exit(0);
        }
        if(q&(1<<depth)) {
            if(onech != nullptr && onech->stsize != 0) return onech->lowestXOR(q);
            else return ((zeroch->lowestXOR(q))|(1<<depth));
        } else {
            if(zeroch != nullptr && zeroch->stsize != 0) return zeroch->lowestXOR(q);
            else return ((onech->lowestXOR(q))|(1<<depth));
        }
    }
};

vector<int> msg;

int main() {
    BTN* root = new BTN(31);
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        int v; cin >> v;
        msg.push_back(v);
    }
    for(int i=0; i<n; i++) {
        int v; cin >> v;
        root->insert(v);
    }
    for(int i=0; i<n; i++) {
        if(i != 0) cout << ' ';
        int lx = root->lowestXOR(msg[i]);
        cout << lx;
        root->remove(msg[i]^lx);
    }
    cout << endl;
}
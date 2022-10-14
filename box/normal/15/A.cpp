#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<double> s;

struct interv {
    double begin, end;
};

vector<interv> ivs;

bool ipi(double a, interv b) {
    return (b.begin < a && a < b.end);
}

bool ovl(interv a, interv b) {
    return ipi(a.begin, b) || ipi(a.end, b) || ipi(b.begin, a) || ipi(b.end, a);
}

int main() {
    int n, t; cin >> n >> t;
    for(int i=0; i<n; i++) {
        int center, size; cin >> center >> size;
        ivs.push_back({center-size/2.0, center+size/2.0});
    }
    for(int i=0; i<n; i++) {
        // aligned to this house's beginning
        interv newhouse; newhouse.end = ivs[i].begin; newhouse.begin = newhouse.end - t;
        bool in = false;
        for(int j=0; j<n; j++) {
            if(ovl(newhouse, ivs[j])) {
                in = true;
                break;
            } else if(j != i && newhouse.begin == ivs[j].begin && newhouse.end == ivs[j].end) {
                in = true;
                break;
            }
        }
        if(!in) s.insert(newhouse.end);
        newhouse.begin = ivs[i].end; newhouse.end = newhouse.begin + t;
        in = false;
        for(int j=0; j<n; j++) {
            if(ovl(newhouse, ivs[j])) {
                in = true;
                break;
            } else if(j != i && newhouse.begin == ivs[j].begin && newhouse.end == ivs[j].end) {
                in = true;
                break;
            }
        }
        if(!in) s.insert(newhouse.end);
    }
    cout << s.size() << endl;
}
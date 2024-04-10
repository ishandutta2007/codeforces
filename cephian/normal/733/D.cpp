#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

int n;
map<pii,vector<pii>> m;

void go(int a, int b, int c, int i) {
    if(a > b) swap(a,b);
    m[pii(a,b)].push_back(pii(c,i));
}

using namespace std;


int mx1 = 0;
int a1 = -1;

int mx2=0;
int c=-1,d=-1;


int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int a,b,c;
        cin >> a >> b >> c;
        go(a,b,c,i);
        go(b,c,a,i);
        go(c,a,b,i);
        int l = min(a,min(b,c));
        if(l > mx1) {
            mx1 = l;
            a1 = i;
        }
    }
    for(auto k : m) {
        int l = min(k.first.first,k.first.second);
        vector<pii>& v = k.second;
        if(v.size() < 2) continue;
        sort(v.rbegin(),v.rend());
        l = min(l,v[0].first+v[1].first);
        if(l > mx2) {
            mx2 = l;
            c = v[0].second;
            d = v[1].second;
        }
    }

    if(mx1 >= mx2) {
        cout << "1\n" << a1+1 << "\n";
    } else {
        cout << "2\n" << c+1 << " " << d+1 << "\n";
    }
    return 0;
}
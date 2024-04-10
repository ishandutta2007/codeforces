#include <iostream>
#include <vector>

using namespace std;

int n,m;
int a[505],b[505];
vector<int> dv;

vector<int> v,w;

vector<int> c,d;

bool solve(int j) {
    int offs = dv[j]+1;
    v.clear();
    for(int i = dv[j]; i < dv[j+1]; ++i)
        v.push_back(a[i]);
    while(v.size() > 1) {
        int mx = 0;
        for(int i = 0; i < v.size(); ++i)
            if(v[i] > mx)
                mx = v[i];
        int rem = -1;
        for(int i = 0; i < v.size(); ++i) {
            if(v[i] != mx) continue;
            if(i != 0 && v[i-1] != mx) {
                v[i] += v[i-1];
                c.push_back(offs+i);
                d.push_back('L');
                rem = i-1;
                break;
            }
            if(i != v.size()-1 && v[i+1] != mx) {
                v[i] += v[i+1];
                c.push_back(offs+i);
                d.push_back('R');
                rem = i+1;
                break;
            }
        }
        if(rem == -1) {
            return false;
        }
        w.clear();
        for(int i = 0; i < v.size(); ++i) {
            if(i == rem) continue;
            w.push_back(v[i]);
        }
        swap(v,w);
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> m;
    int l = 0;
    for(int i = 0; i < m; ++i) {
        cin >> b[i];
        int cur = 0;
        dv.push_back(l);
        while(l < n && cur < b[i]) {
            cur += a[l++];
        }
        if(b[i] != cur) {
            cout << "NO\n";
            return 0;
        }
    }
    if(l != n) {
        cout << "NO\n";
        return 0;
    }
    dv.push_back(n);
    for(int i = dv.size()-2; i >= 0; --i) {
        if(!solve(i)) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for(int i = 0; i < c.size(); ++i) {
        cout << c[i] << " " << char(d[i]) << "\n";
    }
    return 0;
}
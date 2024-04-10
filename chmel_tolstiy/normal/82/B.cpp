#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>

using namespace std;

vector<int> v[1<<15];
int n, m;
int T;

void print(set<int>& s) {
    printf("%d", s.size());
    for (set<int>::iterator i = s.begin(); i != s.end(); i++) 
        printf(" %d", *i);
    printf("\n");
}

int main() {
    cin >> n;
    m = n * (n - 1) / 2;
    T = 1 << 20;
    
    for (int i = 0; i < m; i++) {
        int k; scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int x; scanf("%d", &x);
            v[i].push_back(x);
            T = min(T, x);
        }
        sort(v[i].begin(), v[i].end());
    }
    
    if (n == 2) {
        cout << 1 << ' ' << T << endl;
        cout << v[0].size() - 1;
        for (int i = 1; i < v[0].size(); i++) cout << ' ' << v[0][i];
        cout << endl;
        return 0;
    }
    
    for (int it = 0; it < m; it++) for (int jt = it+1; jt < m; jt++) {
        if (v[it][0] == T && v[jt][0] == T) {
            vector<int>& vi = v[it];
            vector<int>& vj = v[jt];
            
            set<int> v2(vj.begin(), vj.end());
            set<int> v1;
            
            for (int i = 0; i < vi.size(); i++) {
                if (v2.count(vi[i])) v1.insert(vi[i]);
            }
            
            print(v1);
            
            for (int kt = it; kt < m; kt++) if (v[kt][0] == T) {
                v2.clear();
                vector<int>& vk = v[kt];
                for (int i = 0; i < vk.size(); i++) {
                    if (v1.count(vk[i]) == 0) v2.insert(vk[i]);
                }
                print(v2);
            }
            
            return 0;
        }
    }
    
    return 0;
}
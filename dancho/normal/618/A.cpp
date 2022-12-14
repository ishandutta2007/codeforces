#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        v.push_back(1);
        while (v.size() >= 2 && v[v.size() - 1] == v[v.size() - 2]) {
            int u = v.back();
            v.pop_back();
            v.pop_back(); 
            v.push_back(u + 1);
        }
    }
    for (int i = 0; i < (int) v.size(); ++i) {
        printf("%d%c", v[i], " \n"[i + 1 == (int) v.size()]);
    }
    return 0;
}
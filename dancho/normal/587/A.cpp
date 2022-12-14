#include <cstdio>
#include <set>
using namespace std;

set<int> s;

void add(int a) {
    if (s.find(a) != s.end()) {
        s.erase(a);
        add(a + 1);
    } else {
        s.insert(a);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        add(a);
    }
    printf("%d\n", (int) s.size());
    return 0;
}
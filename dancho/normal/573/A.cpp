#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

set<int> s;
int main() {
    int n, a;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        while (a % 2 == 0) {
            a /= 2;
        }
        while (a % 3 == 0) {
            a /= 3;
        }
        s.insert(a);
    }
    if (s.size() == 1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
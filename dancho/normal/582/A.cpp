#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int n;
vector<int> ans;
multiset<int> us;
priority_queue<int> pq;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n * n; ++i) {
        int a;
        scanf("%d", &a);
        pq.push(a);
    }

    while (pq.size()) {
        int a = pq.top();
        pq.pop();
        multiset<int>::iterator it = us.find(a);
        if (it != us.end()) {
            us.erase(it);
            continue;
        }
        printf("%d ", a);
        for (int i = 0; i < (int) ans.size(); ++i) {
            int g = gcd(ans[i], a);
            us.insert(g);
            us.insert(g);
        }
        ans.push_back(a);
    }
    printf("\n");
    return 0;
}
//  ( -)
#include <cstdio>
#include <vector>
static const int MAXN = 1e5 + 4;

long long last_ans = -1;
std::vector<int> v;

inline void insert(int arg) {
    v.insert(std::lower_bound(v.begin(), v.end(), arg), arg);
}
inline void remove(int arg) {
    v.erase(std::lower_bound(v.begin(), v.end(), arg));
}
inline long long query_sum() {
    if (last_ans != -1) return last_ans;
    long long ans = 0;
    for (int i = 2; i < (int)v.size(); i += 5) ans += v[i];
    return (last_ans = ans);
}

int main()
{
    int n;
    scanf("%d", &n);
    char op[24]; int arg;
    for (int i = 0; i < n; ++i) {
        scanf("%s", op);
        switch (op[0]) {
            case 'a': scanf("%d", &arg); insert(arg); last_ans = -1; break;
            case 'd': scanf("%d", &arg); remove(arg); last_ans = -1; break;
            case 's': printf("%I64d\n", query_sum()); break;
            default: puts("> <"); break;
        }
    }
    return 0;
}
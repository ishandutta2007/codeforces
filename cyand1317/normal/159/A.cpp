#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <utility>
typedef long long int64;
typedef unsigned long long uint64;
static const int MAXN = 2005;

typedef std::pair<uint64, uint64> hash_t;
static const uint64 BOUND = 1e16;
inline hash_t hash(const char *s) {
    uint64 a = 0, b = 0;
    for (; *s; ++s) {
        if ((b = b * 26 + (*s - 'a')) >= BOUND) {
            a += b / BOUND; b %= BOUND;
        }
    }
    return hash_t(a, b);
}
std::map<hash_t, int> id;
char *name[MAXN];
inline int get_id(const char *s) {
    hash_t h = hash(s);
    std::map<hash_t, int>::iterator p = id.find(h);
    if (p == id.end()) {
        strcpy(name[(int)id.size()] = new char[25](), s);
        id.insert(std::make_pair(h, (int)id.size()));
        return (int)id.size() - 1;
    } else {
        return p->second;
    }
}

int n, d;
int sender, receiver, t;
std::set<int> sent[MAXN][MAXN];
bool is_friend[MAXN][MAXN] = { false };
int friends_pairs;

int main()
{
    scanf("%d%d", &n, &d);

    char s1[25], s2[25];
    for (int i = 0; i < n; ++i) {
        scanf("%s%s%d", s1, s2, &t);
        sender = get_id(s1);
        receiver = get_id(s2);
        if (sent[receiver][sender].lower_bound(t - d) != sent[receiver][sender].lower_bound(t) && !is_friend[receiver][sender]) {
            is_friend[receiver][sender] = is_friend[sender][receiver] = true;
            ++friends_pairs;
        }
        sent[sender][receiver].insert(t);
    }

    printf("%d\n", friends_pairs);
    for (int i = 0; i < (int)id.size(); ++i)
        for (int j = i + 1; j < (int)id.size(); ++j)
            if (is_friend[i][j]) printf("%s %s\n", name[i], name[j]);
    return 0;
}
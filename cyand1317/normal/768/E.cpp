#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
static const int MAXN = 1e6 + 5;
static const int MAXS = 60;
typedef std::map<std::vector<int>, int> hasher;
static const int MAX_HASHES = 1e6;

int n, s[MAXN];
/*int sg[MAXS + 1][MAX_HASHES];
hasher h; int sz = 0;

inline int get_hash(const std::vector<int> &key) {
    hasher::iterator i = h.find(key);
    if (i == h.end()) return (h[key] = sz++); else return i->second;
}

int calc_sg(int s, const std::vector<int> flags) {
    if (s == 0) return 0;
    int id = get_hash(flags);
    if (sg[s][id] != -1) return sg[s][id];
    std::vector<int> succs, new_flags;
    for (int i = 1; i <= s; ++i) {
        if (*std::lower_bound(flags.begin(), flags.end(), i) != i) {
            new_flags = flags;
            new_flags.push_back(i);
            std::sort(new_flags.begin(), new_flags.end());
            int res = calc_sg(s - i, new_flags);
            if (res != -1) succs.push_back(res);
        }
    }
    if (succs.empty()) return -1;
    std::sort(succs.begin(), succs.end());
    int mex = 0;
    for (int i = 0; i < (int)succs.size(); ++i)
        if (succs[i] >= mex + 2) return (sg[s][id] = mex + 1); else mex = succs[i];
    return (sg[s][id] = mex + 1);
}*/

int sg[MAXS + 1];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &s[i]);

    /*get_hash(std::vector<int>(1, 0));
    memset(sg, -1, sizeof sg);
    for (int i = 1; i <= MAXS; ++i) {
        calc_sg(i, std::vector<int>(1, 0));
    }*/

    for (int i = 1; i <= 2; ++i) sg[i] = 1;
    for (int i = 3; i <= 5; ++i) sg[i] = 2;
    for (int i = 6; i <= 9; ++i) sg[i] = 3;
    for (int i = 10; i <= 14; ++i) sg[i] = 4;
    for (int i = 15; i <= 20; ++i) sg[i] = 5;
    for (int i = 21; i <= 27; ++i) sg[i] = 6;
    for (int i = 28; i <= 35; ++i) sg[i] = 7;
    for (int i = 36; i <= 44; ++i) sg[i] = 8;
    for (int i = 45; i <= 54; ++i) sg[i] = 9;
    for (int i = 55; i <= 60; ++i) sg[i] = 10;

    int sg_sum = 0;
    for (int i = 0; i < n; ++i) sg_sum ^= sg[s[i]];
    puts(sg_sum != 0 ? "NO" : "YES");

    return 0;
}
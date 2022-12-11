#include <cstdio>
#include <algorithm>
#include <set>
#include <utility>
static const int MAXN = 100005;

int n = 0, m, ans_len = 0;
char s[MAXN], ans[MAXN] = { '\0' };
std::pair<char, int> p[MAXN];
std::set<int> marked;
std::multiset<int> distance;

int main()
{
    scanf("%d", &m); getchar();
    while ((s[n] = getchar()) >= 'a' && s[n] <= 'z') ++n;
    for (int i = 0; i < n; ++i) p[i] = std::make_pair(s[i], i);
    std::sort(p, p + n);

    marked.insert(-1);
    marked.insert(n);
    distance.insert(n + 1);
    for (char c = 'a'; c <= 'z'; ++c) {
        //printf("=== %c ===\n", c);
        for (int i = 0; i < n; ++i) if (p[i].first == c) {  // Whatever > <
            std::set<int>::iterator prev = marked.lower_bound(p[i].second), succ = prev--;
            int j = i + 1;
            while (j < n && p[j].first == c && p[j].second < *succ) ++j;
            int last_marked = *prev;
            //printf("%d - %d\n", i, j);
            if (*succ <= last_marked + m) continue;
            for (int k = i; k < j; ++k) {
                while (k < j && p[k].second <= last_marked + m) ++k; --k;
                if (k < i || p[k].second == last_marked) break;
                prev = marked.lower_bound(p[k].second), succ = prev--;
                ans[ans_len++] = p[k].first;
                //printf("%d [%c %d]\n", k, p[k].first, p[k].second);
                marked.insert(p[k].second);
                distance.erase(distance.find(*succ - *prev));
                distance.insert(*succ - p[k].second);
                distance.insert(p[k].second - *prev);
                last_marked = p[k].second;
                if (*succ <= last_marked + m) break;
            }
            i = j - 1;
        }
        if (*(distance.rbegin()) <= m) break;
        for (int i = 0; i < n; ++i) if (p[i].first == c) {
            if (marked.find(p[i].second) != marked.end()) continue;
            std::set<int>::iterator prev = marked.lower_bound(p[i].second), succ = prev--;
            ans[ans_len++] = p[i].first;
            //printf("%d [%c %d]  *\n", i, p[i].first, p[i].second);
            marked.insert(p[i].second);
            distance.erase(distance.find(*succ - *prev));
            distance.insert(*succ - p[i].second);
            distance.insert(p[i].second - *prev);
        }
    }

    puts(ans);
    return 0;
}
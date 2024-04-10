#include <cstdio>
#include <set>
static const int MAXN = 200007;

bool fraction[128];
int n;
std::set<int> pos[2];

int main()
{
    fraction['D'] = 0;
    fraction['R'] = 1;
    scanf("%d", &n); getchar();
    for (int i = 0; i < n; ++i) pos[fraction[getchar()]].insert(i);

    while (pos[0].size() > 0 && pos[1].size() > 0) {
        std::set<int>::iterator ptr[2];
        int turn_progress = 0;
        while (pos[0].size() > 0 && pos[1].size() > 0 &&
            (turn_progress <= *pos[0].rbegin() || turn_progress <= *pos[1].rbegin()))
        {
            ptr[0] = pos[0].lower_bound(turn_progress);
            ptr[1] = pos[1].lower_bound(turn_progress);
            if (ptr[1] == pos[1].end() || (ptr[0] != pos[0].end() && *ptr[0] < *ptr[1])) {
                pos[1].erase(ptr[1] == pos[1].end() ? pos[1].begin() : ptr[1]);
                turn_progress = *ptr[0] + 1;
            } else {
                pos[0].erase(ptr[0] == pos[0].end() ? pos[0].begin() : ptr[0]);
                turn_progress = *ptr[1] + 1;
            }
        }
    }

    puts(pos[0].size() == 0 ? "R" : "D");
    return 0;
}
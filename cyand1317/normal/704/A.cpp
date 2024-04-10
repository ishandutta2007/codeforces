#include <cstdio>
#include <queue>
static const int MAXN = 300004;
static const int MAXQ = 300004;

int n, q, ans = 0;
bool is_read[MAXQ] = { false };
std::vector<int> unread_by_app[MAXN];
std::queue<int> unread_global;

int main()
{
    scanf("%d%d", &n, &q);

    int id = 0;
    int op, arg;
    for (int q_id = 0; q_id < q; ++q_id) {
        scanf("%d%d", &op, &arg);
        if (op == 1) {
            unread_by_app[arg].push_back(id);
            unread_global.push(id);
            ++ans; ++id;
        } else if (op == 2) {
            for (std::vector<int>::iterator i = unread_by_app[arg].begin();
                i != unread_by_app[arg].end(); ++i)
            {
                if (!is_read[*i]) { is_read[*i] = true; --ans; }
            }
            unread_by_app[arg].clear();
        } else {    // op == 3
            while (!unread_global.empty() && unread_global.front() < arg) {
                if (!is_read[unread_global.front()]) {
                    is_read[unread_global.front()] = true; --ans;
                }
                unread_global.pop();
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
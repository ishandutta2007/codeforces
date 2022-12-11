#include <cstdio>
#include <functional>
#include <queue>
#include <vector>
static const int MAXN = 450006;

int ops_ct = 0;
char ops[MAXN][24];

int main()
{
    int n;
    scanf("%d", &n);

    std::priority_queue<int,
        std::vector<int>,
        std::greater<int>
    > heap;
    char op[24]; int arg;
    do {
        scanf("%s", op);
        if (op[0] == 'i') {
            scanf("%d", &arg);
            heap.push(arg);
            sprintf(ops[ops_ct++], "insert %d", arg);
        } else if (op[0] == 'r') {
            if (heap.empty()) {
                heap.push(233333);
                sprintf(ops[ops_ct++], "insert 233333");
            }
            heap.pop();
            sprintf(ops[ops_ct++], "removeMin");
        } else if (op[0] == 'g') {
            scanf("%d", &arg);
            while (!heap.empty() && heap.top() < arg) {
                heap.pop();
                sprintf(ops[ops_ct++], "removeMin");
            }
            if (heap.empty() || heap.top() != arg) {
                heap.push(arg);
                sprintf(ops[ops_ct++], "insert %d", arg);
            }
            sprintf(ops[ops_ct++], "getMin %d", arg);
        }
    } while (--n);
    printf("%d\n", ops_ct);
    for (int i = 0; i < ops_ct; ++i) puts(ops[i]);
    return 0;
}
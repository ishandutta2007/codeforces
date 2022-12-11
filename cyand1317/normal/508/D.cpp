#include <cstdio>
#include <vector>
static const int MAXN = 2e5 + 3;
static const int ALPHA = 64;
static const int MAXV = ALPHA * ALPHA;
static const int MAXE = MAXN;

static const char idx_char[ALPHA] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
inline unsigned char char_idx(const char ch) {
    if (ch >= '0' && ch <= '9') return ch - '0';
    if (ch >= 'A' && ch <= 'Z') return ch - 'A' + 10;
    if (ch >= 'a' && ch <= 'z') return ch - 'a' + 36;
    return -1;
}
inline int vert_idx(const char a, const char b) {
    return a * ALPHA + b;
}

int n;
char s[MAXN][3];

int deg_out[MAXV] = { 0 }, deg_in[MAXV] = { 0 };
int head[MAXV], next[MAXE], dest[MAXE];
inline void add_edge(int u, int v) {
    static int w = 0;
    ++deg_out[u]; ++deg_in[v];
    dest[w] = v; next[w] = head[u]; head[u] = w++;
}
int ct[MAXV] = { 0 };
char ans[MAXN + 2] = { 0 }; int anslen;

int main()
{
    for (int i = 0; i < MAXV; ++i) head[i] = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        getchar(); for (int j = 0; j < 3; ++j) s[i][j] = char_idx(getchar());
        add_edge(vert_idx(s[i][0], s[i][1]), vert_idx(s[i][1], s[i][2]));
    }

    int start = -1, end = -1, candidate = -1;
    bool added = false;
    for (int i = 0; i < MAXV; ++i) if (deg_out[i] - deg_in[i] == 1) {
        if (start == -1) start = i;
        else { puts("NO"); return 0; }
    } else if (deg_out[i] - deg_in[i] == -1) {
        end = i;
    } else if (deg_out[i] - deg_in[i] != 0) {
        puts("NO"); return 0;
    } else if (deg_out[i] != 0) {
        candidate = i;
    }
    if (start == -1) start = candidate;
    else { added = true; add_edge(end, start); start = end; }
    //printf("%c %c\n\n", idx_char[start / ALPHA], idx_char[start % ALPHA]);

    // Find an Eulerian cycle
    // http://www.geeksforgeeks.org/hierholzers-algorithm-directed-graph/ (o
    std::vector<int> path, circuit;
    path.push_back(0);
    int u = start;
    while (!path.empty()) {
        if (deg_out[u]) {
            path.push_back(u);
            int v = dest[head[u]];
            --deg_out[u]; head[u] = next[head[u]];
            u = v;
        } else {
            circuit.push_back(u);
            u = path.back(); path.pop_back();
        }
    }

    /*for (int i = 0; i < (int)circuit.size(); ++i)
        printf("%c %c\n", idx_char[circuit[i] / ALPHA], idx_char[circuit[i] % ALPHA]);*/
    anslen = 0;
    for (int i = (int)circuit.size() - (added ? 2 : 1); i >= 0; --i)
        ans[anslen++] = circuit[i] / ALPHA;
    ans[anslen++] = circuit[0] % ALPHA;

    if (anslen < n + 2) puts("NO");
    else { puts("YES"); for (int i = 0; i < anslen; ++i) putchar(idx_char[ans[i]]); putchar('\n'); }
    return 0;
}
#include <cstdio>

int n, m_i, c_i;
int m_ct = 0, c_ct = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &m_i, &c_i);
        if (m_i > c_i) ++m_ct;
        else if (m_i < c_i) ++c_ct;
    }
    if (m_ct > c_ct) puts("Mishka");
    else if (m_ct < c_ct) puts("Chris");
    else puts("Friendship is magic!^^");
    return 0;
}
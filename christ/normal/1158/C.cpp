#include <bits/stdc++.h>
using namespace std;
const int MN = 5e5 + 5;
vector<int> where[MN];
bool idk[MN];
int main() {
    int t;
    scanf ("%d",&t);
    while (t--) {
        int n;
        scanf ("%d",&n);
        for (int i = 1; i <= n+1; i++) where[i].clear(), idk[i] = 0;
        vector<int> nxt(n+1), p(n+1);
        for (int i = 1; i <= n; i++) {
            scanf ("%d",&nxt[i]);
            if (~nxt[i]) where[nxt[i]].push_back(i);
            else idk[i] = 1;
        }
        int mx = n;
        for (int i = n+1; i >= 1; i--) {
            if (idk[i]) p[i] = mx--;
            for (int j : where[i]) p[j] = mx--;
        }
        vector<int> check(n+1); vector<int> st;
        fill(check.begin(),check.end(),n+1);
        for (int i = 1; i <= n; i++) {
            while (!st.empty() && p[st.back()] < p[i]) {
                check[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
        bool good = 1;
        for (int i = 1; i <= n; i++) if (nxt[i] != -1 && check[i] != nxt[i]) good = 0;
        if (!good) {
            printf ("-1\n");
            continue;
        }
        for (int i = 1; i <= n; i++) printf ("%d ",p[i]);
        printf ("\n");
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Pair;

int V[500005];
int Cnt[5000000];

void Read(int &a) {
    char c;
    for(c = getchar(); !isdigit(c); c = getchar());
    for(a = 0; isdigit(c); c = getchar())
        a = (a << 1) + (a << 3) + c - '0';
}

int main() {
    int n, k, val;
    Read(n); Read(k);

    for(int i=1; i<=n; i++) Read(V[i]);

    int j = 0, cnt = 0, bb = 1, ba = n;
    for(int i=1; i<=n; i++) {
        while(j < n && (cnt < k || (cnt == k && Cnt[V[j+1]] > 0))) {
            j += 1;
            Cnt[V[j]] += 1;
            if(Cnt[V[j]] == 1) cnt += 1;
        }

        if(bb - ba < j - i) bb = j, ba = i;

        Cnt[V[i]] -= 1;
        if(Cnt[V[i]] == 0) cnt -= 1;
    }

    cout << ba << " " << bb;
}
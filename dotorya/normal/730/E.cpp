#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1034567891;

int in[105][2];
int main() {
    int N, i, j;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        scanf("%d %d", in[i], in[i]+1);
        in[i][1] += in[i][0];
    }

    int ans = 0;
    for(i = 1; i <= N; i++) {
        for(j = i+1; j <= N; j++) {
            int c1 = 1;
            if(pii(in[i][0], -i) < pii(in[j][0], -j)) c1 = 0;

            int c4 = 1;
            if(pii(in[i][1], -i) < pii(in[j][1], -j)) c4 = 0;

            int c2 = 1;
            if(pii(in[i][0], -i) < pii(in[j][1], -j)) c2 = 0;

            int c3 = 1;
            if(pii(in[i][1], -i) < pii(in[j][0], -j)) c3 = 0;

            ans += max(((c1^c3) + (c3^c4)), ((c1^c2)+(c2^c4)));
        }
    }
    return !printf("%d\n", ans);
}
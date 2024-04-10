#include <stdio.h>
#include <vector>
int d[605][2];
using namespace std;
struct data {
    data() {
        data(0,0);
    }
    data(int a, int b) {
        idx = a, pos = b;
    }
    int idx, pos;
} tmp;
vector <data> V;
vector <char> ANS;
int main() {
    int N, i, j, cnt = 1;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) scanf("%d %d", &d[i][0], &d[i][1]);
    for(i = 1; i <= 2*N; i++) {
        if(V.empty()) {
            V.push_back(data(cnt, i));
            ANS.push_back('(');
            cnt++;
            continue;
        }
        tmp = V.back();
        if(tmp.pos + d[tmp.idx][0] <= i) {
            if(tmp.pos + d[tmp.idx][1] < i) break;
            ANS.push_back(')');
            V.pop_back();
        }
        else {
            if(cnt == N+1) break;
            V.push_back(data(cnt, i));
            ANS.push_back('(');
            cnt++;
        }
    }
    if(i != 2*N+1) {
        printf("IMPOSSIBLE");
        return 0;
    }
    for(i = 0; i < 2*N; i++) printf("%c", ANS[i]);
    return 0;
}
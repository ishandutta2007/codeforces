#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> ANS;
struct data {
    int chk, num;
    bool operator < (const data & l) const {
        if(num != l.num) return num < l.num;
        else return chk < l.chk;
    }
} d[105];
int main() {
    int N, K, i;
    scanf("%d %d", &N, &K);
    for(i = 1; i <= N; i++) {
        scanf("%d", &d[i].num);
        d[i].chk = i;
    }
    sort(d+1, d+N+1);
    int sum = 0;
    for(i = 1; i <= N; i++) {
        if(sum + d[i].num > K) break;
        ANS.push_back(d[i].chk);
        sum += d[i].num;
    }
    printf("%d\n", ANS.size());
    for(i = 0; i < ANS.size(); i++) printf("%d ", ANS[i]);
    return 0;
}
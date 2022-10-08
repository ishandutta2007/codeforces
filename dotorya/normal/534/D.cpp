#include <stdio.h>
#include <vector>
using namespace std;
vector <int> stu[200050];
int ans[200050];
int main() {
    int N, i, t;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        scanf("%d", &t);
        stu[t].push_back(i);
    }
    t = 0;
    if(stu[0].empty()) {
        printf("Impossible");
        return 0;
    }
    for(i = 1; i <= N; i++) {
        int t2 = stu[t].back();
        ans[i] = t2;
        stu[t].pop_back();
        if(i == N) continue;
        if(!stu[t+1].empty()) t++;
        else {
            t -= 2;
            while(t >= 0 && stu[t].empty()) t -= 3;
            if(t < 0) break;
        }
    }
    if(i != N+1) printf("Impossible");
    else {
        printf("Possible\n");
        for(i = 1; i <= N; i++) printf("%d ", ans[i]);
    }
    return 0;
}
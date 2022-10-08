#include <stdio.h>
#include <vector>
using namespace std;
struct data {
    data() {
        data(0,0);
    }
    data(int x, int y) {
        a = x, b = y;
    }
    int a, b;
};
int chk[100050];
vector <int> tmp;
vector <data> ans;
int main() {
    int i, j, N, t;
    scanf("%d", &N);
    for(i = 3; i <= N; i++) {
        if(chk[i] == 1) continue;
        if(i % 2 == 0 && chk[i/2] == 1) continue;
        if(i * 2 > N) continue;
        tmp.push_back(i);
        for(j = 3; i*j <= N; j++) {
            if(chk[i*j] == 1) continue;
            tmp.push_back(i*j);
        }
        if(tmp.size() % 2 == 1) tmp.push_back(2*i);
        for(j = 0; j < tmp.size()/2; j++) {
            ans.push_back(data(tmp[2*j], tmp[2*j+1]));
            chk[tmp[2*j]] = chk[tmp[2*j+1]] = 1;
        }
        tmp.clear();
    }
    for(i = 2; i <= N; i+=2) {
        if(chk[i] == 0) tmp.push_back(i);
    }
    for(i = 0; i < tmp.size()/2; i++) ans.push_back(data(tmp[2*i], tmp[2*i+1]));
    printf("%d\n", ans.size());
    for(i = 0; i < ans.size(); i++) printf("%d %d\n", ans[i].a, ans[i].b);
    return 0;
}
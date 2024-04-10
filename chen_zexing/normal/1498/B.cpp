#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<math.h>
#include<array>
#include<memory.h>
using namespace std;
int w[100005];
int cnt[25];//2 de cnt ci fang
int main() {
    int t = 1;
    scanf("%d",&t);
    while (t--) {
        int n = 0, W = 0;
        cin >> n >> W;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &w[i]);
            for (int j = 0; j <= 20; j++) {
                if ((1 << j) == w[i]) { cnt[j]++; break; }
            }
        }
        //for(int i=0;i<=20;i++) printf("%d ",cnt[i]);puts("");
        int ans = 0;
        int spaceNow = W;
        bool flag = true;
        while (flag) {
            spaceNow = W;
            for (int i = 20; i >= 0; i--) {//yi ceng
                while (cnt[i] != 0 && spaceNow >= (1<<i)) {
                    spaceNow -= (1<<i); cnt[i]--;
                }
                //if (spaceNow == 0)break;
                //if (cnt[i] != 0 && spaceNow < cnt[i])continue;
                //if (cnt[i] == 0)continue;
            }
            ans++;
            flag = false;
            for (int i = 0; i < 25; i++) {
                if (cnt[i] != 0) {
                    flag = true;break;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
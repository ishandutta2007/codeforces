#include <bits/stdc++.h>
using namespace std;
 
const int SIZE = 500001;
int v[SIZE];
int an[501][501];
int main()
{
    int q;
    scanf("%d", &q);
    while(q--) {
        int type_id,x,y;
        scanf("%d%d%d", &type_id, &x, &y);
        if(type_id == 1) {
            v[x] += y;
            for(int mod = 1; mod <= 500; mod++) {
                an[mod][x%mod] += y;
            }
        }
        else {
            if(x <= 500) {
                printf("%d\n",an[x][y]);
            }
            else {
                int ans = 0;
                for(; y < SIZE; y += x) {
                    ans += v[y];
                }
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
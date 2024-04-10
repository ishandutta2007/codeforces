/*  $t$ 
 * +
 */
/*  $t$ 
 * +
 * (x, y)  x  y 
 */
#include<cstdio>
const int MAX_N = 20;
int n, k, t; // 
int e[MAX_N + 1][MAX_N + 1]; // e[x][y] (x, y) 
int choosen[MAX_N + 1];
int mid; // 
int cnt; //     
void dfs(int x, int now_cost_sum) {
    if (x > n) {
        cnt++; //  1
        return;
    }
    dfs(x + 1, now_cost_sum); //  x 
    //  x  t 
    for (int y = 1; y <= n && cnt < t; y++) {
        //  (x, y) 
        if (!choosen[y] && e[x][y] && now_cost_sum + e[x][y] <= mid) { 
            choosen[y] = 1;           //  y 
            dfs(x + 1, now_cost_sum + e[x][y]); //  
            choosen[y] = 0;           //  y 
        }
    }
}
int main() {
    // 
	scanf("%d%d%d", &n, &k, &t);
	for (int i = 1; i <= k; i++) {
        int h, w, r;
		scanf("%d%d%d", &h, &w, &r);
        e[h][w] = r;
    }
    /* * 
     * 
     * [low, high] 
     */
	int low = 0, high = 1000 * n; 
	while (low < high) {
		mid = (low + high) >> 1;
        cnt = 0; // 
        dfs(1, 0);
		if (cnt >= t) high = mid;
        else low = mid + 1;
    }
    printf("%d\n", low);
}
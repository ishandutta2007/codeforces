#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <assert.h>
#include <set>

using namespace std;

int arr[110];
int sol[11000][10];
int sn[11000];
int ansarr[110];
int pos;
int rpos;
priority_queue<pair<int, int>> pq;

void inline pushback() {
    for (int i = 0; i < sn[pos]; i++) pq.emplace(arr[sol[pos][i]], sol[pos][i]);
}

int main() {
    int n;
    scanf("%d", &n);
    int minval = 1000;
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
        pq.emplace(arr[i], i);
        minval = min(minval, arr[i]);
    }
    int tar = minval;
    while (pq.top().first > tar) {
        //puts("===");
        while (pq.top().first > tar && sn[pos] < min(5, n)) {
            //printf("%d > %d\n", pq.top().first, tar);
            int id = pq.top().second;
            sol[pos][sn[pos]++] = id;
            arr[id] = max(0, arr[id] - 1);
            pq.pop();
        }
        //printf("===> %d\n", sn[pos]);
        if (sn[pos] == 0) break;
        else if(sn[pos] == 1) {
            while (sn[rpos] <= 2 && rpos < pos) rpos++;
            if (pos == rpos) {
                int id = pq.top().second;
                pq.pop();
                sol[pos][sn[pos]++] = id;
                arr[id] = max(0, arr[id] - 1);
                tar = arr[id];
                pushback();
            } else {
                pushback();
                sol[pos][sn[pos]++] = sol[rpos][--sn[rpos]];
            }
        } else pushback();
        //printf("===> %d\n", sn[pos]);
        pos++;
    }
    
    printf("%d\n%d\n", tar, pos);
    
    for (int i = 0; i < pos; i++) {
        //printf("===> %d\n", sn[i]);
        for (int j = 0; j < sn[i]; j++) ansarr[sol[i][j]] = 1;
        for (int j = 0; j < n; j++) putchar("01"[ansarr[j]]);
        putchar('\n');
        for (int j = 0; j < sn[i]; j++) ansarr[sol[i][j]] = 0;
    }

	return 0;
}
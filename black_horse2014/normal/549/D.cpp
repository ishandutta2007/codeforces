#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <iostream>
#include <cassert>

using namespace std;

typedef long long LL;
typedef double DB;
typedef pair<int, int> PII;
typedef vector<int> VI;

#define X first
#define Y second
#define pb push_back
#define MN 105

int N, M;
char b[MN][MN];
int val[MN][MN];

void add(int x, int y, int v) {
    int yy;
    for (; x < MN; x += x & -x) 
        for (yy = y; yy < MN; yy += yy & -yy)
            val[x][yy] += v;    
}

int get(int x, int y) {
    int rlt = 0, yy;
    for (; x; x -= x & -x) 
        for (yy = y; yy; yy -= yy & -yy) 
            rlt += val[x][yy];
    return rlt;
}

int main() {
    
    int i, j, k, cnt;
    scanf("%d%d", &N, &M);
    for (i = 0; i < N; i++) scanf("%s", b + i);
    cnt = 0;
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= M; j++) {
            int rlt = get(i, j);
            if (b[N - i][M - j] == 'W') {
                if (1 - rlt != 0) add(i, j, 1 - rlt), cnt++;    
            } else {
                if (-1 - rlt != 0) add(i, j, -1 - rlt), cnt++;  
            }
        }
    }
    printf("%d\n", cnt);
    
    return 0;
}
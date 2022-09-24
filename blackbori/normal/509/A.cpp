#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

int N;
int D[12][12];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d",&N);

    int i,j;
    D[0][1] = 1;
    for(i=1; i<=N; i++){
        for(j=1; j<=N; j++){
            D[i][j] = D[i-1][j] + D[i][j-1];
        }
    }

    printf("%d\n",D[N][N]);

    return 0;
}
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

int D[101];
int E[101];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int N,K,i,j,l;
    scanf("%d %d",&N,&K);
    for(i=0; i<N; i++) scanf("%d",&D[i]);

    for(j=0; j<K; j++){
        int m = 2147483647;
        for(i=0; i<N; i++){
            if(m > D[i]) m = D[i];
        }
        for(i=0; i<N; i++){
            D[i] -= m;
        }
        E[j] = m;
    }

    for(i=0; i<N; i++){
        if(D[i] > K){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    for(i=0; i<N; i++){
        for(j=0; j<K; j++){
            for(l=0; l<E[j]; l++){
                printf("%d ",j+1);
            }
            if(D[i] > 0){
                printf("%d ",j+1);
                D[i]--;
            }
        }
        printf("\n");
    }

    return 0;
}
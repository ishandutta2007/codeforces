#include <cstdio>
#include <vector>

bool Graph[101][101][101];
int N,M,Q;
int E;

bool Dfs(int s,int c)
{
    if(s == E) return 1;
    int sum=0, i;
    for(i=1; i<=N; i++){
        if(Graph[c][s][i]){
//            printf("%d %d %d\n",s,c,i);
            Graph[c][s][i] = false;
            Graph[c][i][s] = false;
            sum += Dfs(i,c);
            Graph[c][s][i] = true;
            Graph[c][i][s] = true;
        }
        if(sum == 1) return 1;
    }
    return 0;
}

int query(int s)
{
    int sum=0;
    int i,j;
    for(i=1; i<=M; i++){
        sum += Dfs(s,i);
    }
    return sum;
}

int main()
{
    scanf("%d %d",&N,&M);
    int i,a,b,c;
    for(i=1; i<=M; i++){
        scanf("%d %d %d",&a,&b,&c);
        Graph[c][a][b] = true;
        Graph[c][b][a] = true;
    }

//    for(i=1; i<=4;i++){ for(int j=1;j<=4; j++) {for(int l=1; l<=4; l++) printf("%d ",Graph[i][j][l]); printf("\n");} printf("\n");}

    scanf("%d",&Q);
    for(i=0; i<Q; i++){
        scanf("%d %d",&a,&E);
        printf("%d\n",query(a));
    }

    return 0;
}
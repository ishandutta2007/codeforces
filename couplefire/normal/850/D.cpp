#include<cstdio>
#include<algorithm>
using namespace std;
int D[70][2510][40], w[40], n, Path[70][2510][40];
int Res[70][70];
struct point{
    int a, d;
    bool operator <(const point &p)const{
        return d<p.d;
    }
}R[70];
bool Pos(int m){
    int i, j, k;
    for(i=0;i<=m;i++){
        int ed = min(m*(m-1)/2, i*(m-1));
        for(j=i*(i-1)/2;j<=ed;j++) for(k=1;k<=n;k++)D[i][j][k]=0;
    }
    D[0][0][0] = 1;
    for(i=0;i<m;i++){
        int ed = min(m*(m-1)/2, i*(m-1));
        for(j=i*(i-1)/2;j<=ed;j++){
            for(k=0;k<=n;k++){
                if(D[i][j][k]){
                    if(k){
                        D[i+1][j+w[k]][k]=1;
                        Path[i+1][j+w[k]][k] = 0;
                    }
                    if(k!=n){
                        D[i+1][j+w[k+1]][k+1]=1;
                        Path[i+1][j+w[k+1]][k+1] = 1;
                    }
                }
            }
        }
    }
    if(!D[m][m*(m-1)/2][n])return false;
    printf("%d\n",m);
    int a = m, b = m*(m-1)/2, c = n, cnt = 0;
    while(a){
        cnt++;
        R[cnt] = {cnt, w[c]};
        int t = Path[a][b][c];
        a--,b-=w[c],c-=t;
        
    }
    for(i=1;i<=m;i++){
        sort(R+1,R+cnt+1);
        int x = R[cnt].a, d = R[cnt].d;
        for(j=1;j<cnt;j++){
            if(j<=d)Res[x][R[j].a]=1;
            else Res[R[j].a][x]=1, R[j].d--;
        }
        cnt--;
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=m;j++){
            printf("%d",Res[i][j]);
        }
        printf("\n");
    }
    return true;
}
int main(){
    int i, M = 0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        M = max(M, w[i]);
    }
    sort(w+1,w+n+1);
    for(i=M+1;i<=61;i++){
        if(Pos(i)){
            break;
        }
    }
    if(i==62){
        printf("=(\n");
        return 0;
    }
}
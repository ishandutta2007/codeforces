#include <cstdio>
int main(){
    int arr[3][3], n,
        dx[4] = {1,0,-1,0}, dy[4]={0,1,0,-1};
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            arr[i][j] = 1;
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j){
            scanf("%d", &n);
            if(n&1){
                arr[i][j] ^= 1;
                for(int k = 0; k < 4; ++k){
                    int x = i+dx[k], y = j+dy[k];
                    if(x>=0 && y>=0 && x<=2 && y<=2){
                        arr[x][y]^=1;
                    }
                }
            }
        }
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j)
            printf("%d", arr[i][j]);
        puts("");
    }
    return 0;
}
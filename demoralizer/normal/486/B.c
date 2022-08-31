#include<stdio.h>
int main(){
    int n,m;scanf("%d %d",&n,&m);
    int b[n][m],a[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            a[i][j]=1;
            scanf("%d",&b[i][j]);
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(b[i][j]==0){
                for(int z=0;z<n;z++) a[z][j]=0;
                for(int z=0;z<m;z++) a[i][z]=0;
            }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(b[i][j]==1){
                int c=0;
                for(int z=0;z<n;z++) c+=a[z][j];
                for(int z=0;z<m;z++) c+=a[i][z];
                if(c==0){printf("NO");return 0;}
            }
    printf("YES\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) printf("%d ",a[i][j]);
        printf("\n");
    }
}
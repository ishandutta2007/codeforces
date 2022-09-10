#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
unsigned int grid1[500][500][16],grid2[500][500][16];
inline void insert(unsigned int grid[][500][16],int x,int y,int bit){
    grid[x][y][bit>>5]^=((unsigned int)1)<<(bit&31);
}
struct Point{
    long long x,y;
    void scan(){cin>>x>>y;}
}a[500],b[500];
int main(){
    int i,j,k,kk,N,M,an=0;
    scanf("%d%d",&N,&M);
    if(M==0){
        printf("%d\n",N*(N-1)*(N-2)/6);
        return 0;
    }
    for(i=0;i<N;i++)a[i].scan();
    for(i=0;i<M;i++)b[i].scan();
    for(i=0;i<N;i++)
        for(j=i+1;j<N;j++){
            for(k=0;k<M;k++){
                if((a[j].x-a[i].x)*(b[k].y-a[i].y)>(a[j].y-a[i].y)*(b[k].x-a[i].x)){
                    insert(grid1,i,j,k);
                }
                else{
                    insert(grid2,i,j,k);
                }
            }
        }
    for(i=0;i<N;i++)
        for(j=i+1;j<N;j++)
            for(k=j+1;k<N;k++){
                if((a[j].x-a[i].x)*(a[k].y-a[i].y)>(a[j].y-a[i].y)*(a[k].x-a[i].x)){
                    for(kk=0;!(kk&16);kk++)
                        if(grid1[i][j][kk]&grid1[j][k][kk]&grid2[i][k][kk])break;
                    if(kk==16)an++;
                }
                else{
                    for(kk=0;!(kk&16);kk++)
                        if(grid2[i][j][kk]&grid2[j][k][kk]&grid1[i][k][kk])break;
                    if(kk==16)an++;
                }
            }
    cout<<an<<endl;
    return 0;
}
#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define SIZE 111
int No;
int xx[SIZE],yy[SIZE],e[SIZE][SIZE],used[SIZE],tt;
bool go(int x,int y){
    if(x==y)return 1;
    if(used[x]==tt)return 0;
    int i;
    used[x]=tt;
    for(i=1;i<=No;i++){
        if(e[x][i]){
            if(go(i,y))return 1;
        }
    }
    return 0;
}
int main(){
    int i,j,k,n,ty,x,y;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d",&ty,&x,&y);
        if(ty==1){
            No++;
            xx[No]=x;
            yy[No]=y;
            for(i=1;i<No;i++){
                if((yy[i]>x&&yy[i]<y)||(xx[i]>x&&xx[i]<y))e[i][No]=1;
                if((y>xx[i]&&y<yy[i])||(x>xx[i]&&x<yy[i]))e[No][i]=1;
            }
        }
        else{
            tt++;
            if(go(x,y))puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
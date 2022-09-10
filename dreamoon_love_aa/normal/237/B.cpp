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
#define SIZE 56
int a[SIZE][SIZE],c[SIZE];
struct Point{
    int x,y;
    Point(int _x=0,int _y=0){x=_x;y=_y;}
}pos[SIZE*SIZE];
struct data{
    int x1,y1,x2,y2;
};
vector<data>res;
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=1;i<=n;i++)cin>>c[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=c[i];j++){
            cin>>a[i][j];
            pos[a[i][j]]=Point(i,j);
        }
    int now=1;
    for(i=2;i<=n+50;i++)
        for(j=1;j<i;j++){
            if(c[j]>=i-j){
                if(a[j][i-j]!=now){
                    //for(int ii=1;ii<=n;ii++,puts(""))
                    //    for(int jj=1;jj<=c[ii];jj++)printf(" %d",a[ii][jj]);
                    //for(int ii=1;ii<=4;ii++)printf("[%d,%d]\n",pos[ii].x,pos[ii].y);
                    res.pb((data){j,i-j,pos[now].x,pos[now].y});
                    pos[a[j][i-j]]=Point(pos[now].x,pos[now].y);
                    swap(a[j][i-j],a[pos[now].x][pos[now].y]);  
                    pos[a[j][i-j]]=Point(j,i-j);
                }
                now++;
            }
        }
    printf("%d\n",res.size());
    for(i=0;i<res.size();i++){
        printf("%d %d %d %d\n",res[i].x1,res[i].y1,res[i].x2,res[i].y2);
    }
    return 0;
}
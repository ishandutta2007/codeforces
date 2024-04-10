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
struct Point{
    int x,y;
    Point(int _x=0,int _y=0){x=_x,y=_y;}
    Point operator-(Point b)const{return Point(x-b.x,y-b.y);}
    int operator^(Point b)const{return x*b.y-y*b.x;}
    int operator*(Point b)const{return x*b.x+y*b.y;}
    int dis2(){return x*x+y*y;}
    void scan(){scanf("%d%d",&x,&y);}
}a[8];
int used[8],d[8];
void print(){
    int i;
    puts("YES");
    for(i=0;i<4;i++){
        if(i)putchar(' ');
        printf("%d",d[i]+1);
    }
    puts("");
    for(i=4;i<8;i++){
        if(i>4)putchar(' ');
        printf("%d",d[i]+1);
    }
    puts("");
}
bool test(){
    int r1=(a[d[0]]-a[d[1]]).dis2();
    int r2=(a[d[1]]-a[d[2]]).dis2();
    int r3=(a[d[2]]-a[d[3]]).dis2();
    int r4=(a[d[3]]-a[d[0]]).dis2();
    if(r1==r2&&r3==r4&&r1==r3&&r4){
        if((a[d[0]]-a[d[1]])*(a[d[2]]-a[d[1]])==0
         &&(a[d[1]]-a[d[2]])*(a[d[3]]-a[d[2]])==0
         &&(a[d[2]]-a[d[3]])*(a[d[0]]-a[d[3]])==0
         &&(a[d[3]]-a[d[0]])*(a[d[1]]-a[d[0]])==0){
            if((a[d[4]]-a[d[5]])*(a[d[6]]-a[d[5]])==0
             &&(a[d[5]]-a[d[6]])*(a[d[7]]-a[d[6]])==0
             &&(a[d[6]]-a[d[7]])*(a[d[4]]-a[d[7]])==0
             &&(a[d[7]]-a[d[4]])*(a[d[5]]-a[d[4]])==0){
                int r5=(a[d[0]]-a[d[1]]).dis2();
                int r6=(a[d[1]]-a[d[2]]).dis2();
                int r7=(a[d[2]]-a[d[3]]).dis2();
                int r8=(a[d[3]]-a[d[0]]).dis2();
                if(r5==r7&&r6==r8&&r5&&r6){
                    print();
                    return 1;
                }
            }
        }
    }
    return 0;
    
}
bool dfs(int x){
    if(x==8){
        return test();
    }
    int i;
    for(i=0;i<8;i++){
        if(used[i])continue;
        used[i]=1;
        d[x]=i;
        if(dfs(x+1))return 1;
        used[i]=0;
    }
    return 0;
}
int main(){
    int i,j,k,n;
    for(i=0;i<8;i++)a[i].scan();
    if(!dfs(0))puts("NO");
    return 0;
}
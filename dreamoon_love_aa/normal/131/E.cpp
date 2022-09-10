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
int cs,cnt[100000],an[9];
struct data{
    int x,y,No;
    bool operator<(data b)const{
        if(cs==0)return x<b.x||(x==b.x&&y<b.y);
        else if(cs==1)return x+y<b.x+b.y||(x+y==b.x+b.y&&x<b.x);
        else if(cs==2)return y<b.y||(y==b.y&&x<b.x);
        else if(cs==3)return x-y<b.x-b.y||(x-y==b.x-b.y&&x<b.x);
    }
    bool operator==(data b)const{
        if(cs==0)return x==b.x;
        else if(cs==1)return x+y==b.x+b.y;
        else if(cs==2)return y==b.y;
        else if(cs==3)return x-y==b.x-b.y;
    }
}a[100000];
int main(){
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)scanf("%d%d",&a[i].x,&a[i].y),a[i].No=i;
    for(cs=0;cs<4;cs++){
        sort(a,a+m);
        for(i=1;i<m;i++){
            if(a[i]==a[i-1]){
                cnt[a[i].No]++;
                cnt[a[i-1].No]++;
            }
        }
    }
    for(i=0;i<m;i++)
        an[cnt[i]]++;
    for(i=0;i<=8;i++){
        if(i)putchar(' ');
        printf("%d",an[i]);
    }
    puts("");
    return 0;
}
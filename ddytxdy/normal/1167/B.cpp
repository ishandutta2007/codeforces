#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int ans,x,y,xx,yy,a[7]={0,4,8,15,16,23,42},b[7];
int ask(int x,int y){
    printf("? %d %d\n",x,y);
    fflush(stdout);
    scanf("%d",&ans);
    return ans;
}
void solve(int ans,int &x,int &y){
    for(int i=1;i<=6;i++){
        for(int j=i+1;j<=6;j++){
            if(a[i]*a[j]==ans){
                x=a[i];y=a[j];return;
            }
        }
    }
}
int main(){
    solve(ask(1,2),x,y);
    solve(ask(2,3),xx,yy);
    if(x==xx||x==yy){
        b[2]=x;b[1]=y;b[3]=x==xx?yy:xx;
    }
    else{
        b[2]=y;b[1]=x;b[3]=y==xx?yy:xx;
    }
    solve(ask(4,5),x,y);
    solve(ask(5,6),xx,yy);
    if(x==xx||x==yy){
        b[5]=x;b[4]=y;b[6]=x==xx?yy:xx;
    }
    else{
        b[5]=y;b[4]=x;b[6]=y==xx?yy:xx;
    }
    printf("! ");
    for(int i=1;i<=6;i++)printf("%d ",b[i]);
    return 0;
}
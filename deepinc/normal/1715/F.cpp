#include<bits/stdc++.h>
using namespace std;
long double X,Y;
int main(){
    int n,m;
    cin>>n>>m;
    printf("? %d\n",n*4+2);
    for(int i=1;i<=n;++i) 
        printf("%.15Lf %.15Lf\n",i-1.L,i==1?0:1e-14L),
        printf("%.15Lf %.15Lf\n",i-1.L,m*1.L),
        printf("%.15Lf %.15Lf\n",i-1.L+1e-9L*i,m*1.L),
        printf("%.15Lf %.15Lf\n",i-1.L+1e-9L*i,1e-14L);
    printf("%.15Lf %.15Lf\n",n*1.L,1e-14L);
    printf("%.15Lf %.15Lf\n",n*1.L,0.L);
    fflush(stdout);
    scanf("%Lf",&X); X/=1e-9L; int x=round(X)-2;
    
    printf("? %d\n",m*4+2);
    for(int i=1;i<=m;++i) 
        printf("%.15Lf %.15Lf\n",i==1?0:1e-14L,i-1.L),
        printf("%.15Lf %.15Lf\n",n*1.L,i-1.L),
        printf("%.15Lf %.15Lf\n",n*1.L,i-1.L+1e-9L*i),
        printf("%.15Lf %.15Lf\n",1e-14L,i-1.L+1e-9L*i);
    printf("%.15Lf %.15Lf\n",1e-14L,m*1.L);
    printf("%.15Lf %.15Lf\n",0.L,m*1.L);
    fflush(stdout);
    scanf("%Lf",&Y); Y/=1e-9L; int y=round(Y)-2;
    
    printf("? 4\n"); 
    printf("%.15Lf %.15Lf\n",x+0.L,y+0.L);
    printf("%.15Lf %.15Lf\n",x+10.L,y+0.L);
    printf("%.15Lf %.15Lf\n",x+10.L,y+1.L);
    printf("%.15Lf %.15Lf\n",x+0.L,y+1.L);
    fflush(stdout);
    scanf("%Lf",&Y); Y=y+1-Y;
    printf("? 4\n"); 
    printf("%.15Lf %.15Lf\n",x+0.L,y+0.L);
    printf("%.15Lf %.15Lf\n",x+0.L,y+10.L);
    printf("%.15Lf %.15Lf\n",x+1.L,y+10.L);
    printf("%.15Lf %.15Lf\n",x+1.L,y+0.L);
    fflush(stdout);
    scanf("%Lf",&X); X=x+1-X;
    
    printf("! %.15Lf %.15Lf\n",X,Y);
    fflush(stdout);
}
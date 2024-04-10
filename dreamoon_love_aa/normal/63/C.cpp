#include<stdio.h>
struct data{
    int v,x,y;
}a[12];
int min(int x,int y){return x<y?x:y;}
bool Check(int x,data X){
    int i,s[4],t[4],xx=x,yy=X.v,d[10],e[10],an1=0,an2=0;
    for(i=0;i<10;i++)d[i]=e[i]=0;
    for(i=0;i<4;i++){
        s[i]=xx%10;
        t[i]=yy%10;
        xx/=10;
        yy/=10;
        d[s[i]]++;
        e[t[i]]++;
    }
    for(i=0;i<10;i++)
        if(d[i]>1)return 0;
    for(i=0;i<10;i++)
        an2+=min(d[i],e[i]);
    for(i=0;i<4;i++)
        an1+=(s[i]==t[i])?1:0;
    an2-=an1;
    return an1==X.x&&an2==X.y;
}
main(){
    int n,i,j,an=0,v;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d%d%d",&a[i].v,&a[i].x,&a[i].y);
    for(i=0;i<10000&&an<2;i++){
        for(j=0;j<n;j++)
            if(!Check(i,a[j]))break;
        if(j==n){
            an++;
            v=i;
        }
    }
    if(an==2)puts("Need more data");
    else if(an==0)puts("Incorrect data");
    else printf("%04d\n",v);

}
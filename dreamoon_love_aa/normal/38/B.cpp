#include<stdio.h>
int dx[8]={1,1,2,2,-1,-1,-2,-2};
int dy[8]={2,-2,1,-1,2,-2,1,-1};
struct data{
    int x,y;
    void scan(){
        char s[9];
        scanf("%s",s);
        x=s[0]-'a';
        y=s[1]-'1';
    }
}a[2];
void get(data &X){X.scan();}
main(){
    int i,j,k,an=0;
    get(a[0]);
    get(a[1]);
    for(i=0;i<8;i++)
        if(a[1].x+dx[i]==a[0].x&&a[1].y+dy[i]==a[0].y)break;
    if(i<8)puts("0"); 
    else{
        if(a[0].x==a[1].x||a[0].y==a[1].y)puts("0");
        else{
            for(i=0;i<8;i++)
                for(j=0;j<8;j++){
                    if(i==a[0].x||j==a[0].y)continue;
                    if(i==a[1].x&&j==a[1].y)continue;
                    for(k=0;k<8;k++){
                        if(i+dx[k]==a[0].x&&j+dy[k]==a[0].y)break;
                        if(i+dx[k]==a[1].x&&j+dy[k]==a[1].y)break;
                    }
                    if(k==8)an++;
                }
            printf("%d\n",an);
        }
    }
}
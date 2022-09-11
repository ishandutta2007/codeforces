#include<stdio.h>
int q[50],h,w;
char answer[128][128];
int max(int x,int y){return x>y?x:y;}
bool Out(int x,int y){return x<0||y<0||x>=h||y>=w||answer[x][y];}
int dy[2]={1,-1};
main(){
    int a,b,c,d,n,i,j,nowX,nowY,ud;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&n);
    h=max(b,d);
    w=a+c;
    for(i=0;i<n;i++)scanf("%d",&q[i]);
    puts("YES");
    for(i=0;i<h;i++)
        for(j=0;j<w;j++)answer[i][j]='.';
    for(i=0;i<b;i++)
        for(j=0;j<a;j++)answer[i][j]=0;
    for(i=0;i<d;i++)
        for(j=0;j<c;j++)answer[i][j+a]=0;
    if(a&1){
        nowX=b-1;
        nowY=0;
        ud=1;
    }
    else{
        ud=0;
        nowX=0;
        nowY=0;
    }
    for(i=0;i<n;i++){
        while(q[i]){
            q[i]--;
            answer[nowX][nowY]='a'+i;
            if(Out(nowX+dy[ud],nowY)){
                ud^=1;
                nowY++;
            }
            else{
                nowX+=dy[ud];
            }
        }
    }
    for(i=0;i<h;i++)puts(answer[i]);
}
#include<stdio.h>
#include<string.h>
int an[1000],ann;
int have[2001];
struct data{
    int x,y;
}a[5001];
int sell[2001];
int used[5000];
void twice(){
    int i;
    for(i=0;i<=ann;i++)an[i]<<=1;
    for(i=0;i<ann;i++){
        if(an[i]>9){
            an[i+1]+=an[i]/10;
            an[i]%=10;
        }
    }
    while(an[ann]>9){
        an[ann+1]=an[ann]/10;
        an[ann]%=10;
        ann++;
    }
}
void add1(){
    int i;
    an[0]++;
    for(i=0;i<ann;i++){
        if(an[i]>9){
            an[i+1]+=an[i]/10;
            an[i]%=10;
        }
    }
    while(an[ann]>9){
        an[ann+1]=an[ann]/10;
        an[ann]%=10;
        ann++;
    }
}
void print(){
    int i;
    for(i=ann;i>=0;i--)printf("%d",an[i]);
    puts("");
}
main(){
    memset(sell,-1,sizeof(sell));
    int n,x,i,j;
    char s[8];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s%d",s,&x);
        if(s[0]=='s'){
            sell[x]=i;
            a[i]=(data){0,x};
        }
        else a[i]=(data){1,x};
    }
    for(i=2000;i>=0;i--){
        twice();
        if(sell[i]>=0){
            for(j=sell[i];j>=0;j--){
                if(used[j])break;
                if(a[j].x==1&&a[j].y==i)break;
            }
            if(j>=0&&!used[j]){
                for(;j<=sell[i];j++)used[j]=1;
                add1();
            }
        }
    }
    print();
}
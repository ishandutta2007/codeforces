#include<stdio.h>
#include<string.h>
bool p[20000000];
int pp[4000000],pn,an,a,b,k;
void dfs0(int now,int x,int l,int r){
    if(now>l&&now<=r&&!p[now]){
        p[now]=1;
        an++;
    }
    if(x==pn)return;
    if(x<pn-1&&now<=r/pp[x+1])dfs0(now,x+1,l,r);
    while(now<=r/pp[x]){
        now*=pp[x];
        dfs0(now,x+1,l,r);
    }
}
void dfs1(int now,int x,int cnt){
    if(pp[x]==k){
        if(!cnt)an+=b/now-(a-1)/now;
        else an-=b/now-(a-1)/now;
        return;
    }
    dfs1(now,x+1,cnt);
    if(now<=b/pp[x])dfs1(now*pp[x],x+1,cnt^1);
}
main(){
    int i,j;
    scanf("%d%d%d",&a,&b,&k);
    if(k==2){
        printf("%d\n",b/2-(a-1)/2);
    }
    else if(!(k&1))puts("0");
    else{
        for(i=3;i*i<20000000;i+=2){
            if(!p[i])
                for(j=i*i;j<20000000;j+=i+i)p[j]=1;
        }
        if(k<20000000){
            pp[0]=2;
            pn=1;
            for(i=3;i<20000000;i+=2)
                if(!p[i])pp[pn++]=i;
            if(p[k])puts("0");
            else{
                if(k>100){
                    for(i=0;pp[i]<k;i++);
                    memset(p,0,sizeof(p));
                    dfs0(1,i,(a-1)/k,b/k);
                }
                else{
                    dfs1(k,0,0);
                }
                printf("%d\n",an);
            }
        }
        else{
            for(i=3;i*i<=k;i+=2)
                if(k%i==0)break;
            if(i*i<=k)puts("0");
            else{
                if(a<=k&&k<=b)puts("1");
                else puts("0");
            }
        }
    }
}
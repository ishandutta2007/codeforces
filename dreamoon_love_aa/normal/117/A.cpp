#include<stdio.h>
int F(int s,int f,int t,int m){
    if(s==f)return t;
    int now,dir;
    if((t/(m-1))&1){
        now=m-(t%(m-1));
        if(s<=now){
            t+=(now-s);
            now=s;
            dir=-1;
        }
        else{
            t+=now-1+s-1;
            now=s;
            dir=1;
        }
        
    }
    else{
        now=1+t%(m-1);
        if(s>=now){
            t+=(s-now);
            now=s;
            dir=1;
        }
        else{
            t+=m-now+m-s;
            now=s;
            dir=-1;
        }
    }
    if(dir==-1){
        if(f<=now){
            t+=now-f;
        }
        else{
            t+=now-1+f-1;
        }
    }
    else{
        if(f>=now){
            t+=f-now;
        }
        else{
            t+=m-now+m-f;
        }
    }
    return t;
}
main(){
    int n,m,s,f,t;
    scanf("%d%d",&n,&m);
    while(n--){
        scanf("%d%d%d",&s,&f,&t);
        printf("%d\n",F(s,f,t,m));
    }
}
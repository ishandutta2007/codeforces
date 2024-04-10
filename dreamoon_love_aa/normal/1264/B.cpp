#include<bits/stdc++.h>
#define PB push_back
const int SIZE = 200 * 1000 + 1;
int N,c[SIZE];
int change(){
    for(int i=1;i<N-1;i++){
        if(c[i+1]<=0){
            for(int j=i;j<=N;j++){
                if((i-j)%2==0)c[j]--;
                else c[j]++;
            }
            return i;
        }
    }
    if(c[N]<0){
        c[N-1]--;
        c[N]++;
        return N-1;
    }
    if(c[N]>0){
        c[N]--;
        return N;
    }
    return -1;
}
int main(){
    N=4;
    for(int i=1;i<=N;i++){
        scanf("%d",&c[i]);
    }
    int ll=1;
    int rr=4;
    while(c[ll]==0)ll++;
    while(c[rr]==0)rr--;
    for(int i=ll;i<=rr;i++){
        if(!c[i]){
            puts("NO");
            return 0;
        }
    }
    N=rr-ll+1;
    for(int i=1;i<=N;i++)c[i]=c[ll+i-1];
    for(int i=1;i<=N;i++){
        c[i]=c[i]*2-c[i-1];
    }
    int s=change();
    int t=change();
    int z=change();
    if(z!=-1)return 0*puts("NO");
    if(s==-1){s=N-1,t=N;c[N-1]--;}
    std::vector<int> res{s};
    while(s!=1){
        s--;
        c[s]--;
        //printf("<");
        res.PB(s);
    }
    while(s<t){
        //printf(">");
        res.PB(s+1);
        c[s]--;
        while(c[s]>0){
            //printf("<>");
            res.PB(s);
            res.PB(s+1);
            c[s]-=2;
        }
        s++;
    }
    while(s<N){
        c[s]--;
        //printf(">");
        s++;
        res.PB(s);
    }
    while(s>t){
        s--;
        if(!c[s])break;
        //printf("<");
        res.PB(s);
        c[s]--;
        while(c[s]>0){
            //printf("><");
            res.PB(s+1);
            res.PB(s);
            c[s]-=2;
        }
    }
    puts("YES");
    for(int x:res)printf("%d ",x+ll-2);
}
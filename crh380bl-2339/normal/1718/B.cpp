#include<bits/stdc++.h>
using namespace std;
#define N 100
struct node{
    long long x;
    int y;
    bool operator <(const node z)const{
        if(z.x==x)return y<z.y;
        return x<z.x;
    }
};
priority_queue<node>Q;
long long fib[N+5];
void init(){
    fib[0]=fib[1]=1;
    int i;
    for(i=2;i<=N;++i){
        fib[i]=fib[i-1]+fib[i-2];
    }

}
void work(){
    while(!Q.empty())Q.pop();
    int n,i;
    long long x,s=1;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%lld",&x);
        node tmp;
        tmp.x=x;
        tmp.y=i;
        Q.push(tmp);
        s+=x;
    }
    int y=lower_bound(fib,fib+N+1,s)-fib;
    if(fib[y]!=s){
        puts("NO");
        return;
    }
    int last=-1;
    for(i=y-2;i>=0;--i){
        node tp1=Q.top();
        if(tp1.x<fib[i]){
            puts("NO");
            return;
        }
        if(tp1.x>=fib[i] && tp1.y !=last){
            Q.pop();
            last=tp1.y;
            tp1.x-=fib[i];
            if(tp1.x>0){
                Q.push(tp1);
            }
        }
        else{
            Q.pop();
            if(Q.empty()){
                puts("NO");
                return;
            }
            node tp2=Q.top();
            if(tp2.x<fib[i]){
                puts("NO");
                return;
            }
            Q.pop();
            last=tp2.y;
            tp2.x-=fib[i];
            if(tp2.x>0)Q.push(tp2);
            Q.push(tp1);
        }
    }
    puts("YES");
}
int main(){
    init();
    int T;
    scanf("%d",&T);
    while(T--){
        work();
    }
    return 0;
}
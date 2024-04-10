#include<bits/stdc++.h>
#define ll long long
#define N 505050
using namespace std;
int cas,n,a[N],c[N],A,K;
ll ans=0;
struct node{
    int x;
    bool operator <(const node &a)const{
        return x>a.x;
    }
};
priority_queue<node>Q;
int main(){
    scanf("%d%d",&n,&K);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    scanf("%d",&A);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    while(!Q.empty())Q.pop();
    for(int i=1;i<=n;i++){
        node t;
        t.x=c[i];
        Q.push(t);
        while(!Q.empty()){
            if(K>=a[i])break;
            t=Q.top();Q.pop();
            ans+=t.x;
            K+=A;
        }
        if(K<a[i]){
            printf("-1\n");
            return 0;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
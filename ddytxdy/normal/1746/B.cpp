#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+50;
const double eps=1e-12;
int n,k,T,a[N],ans;
priority_queue<int>q,q2;
void solve(){
    scanf("%d",&n);ans=0;
    while(q.size())q.pop();
    while(q2.size())q2.pop();
    for(int i=1,x;i<=n;i++){
        scanf("%d",&x);
        if(x==1)q.push(-i);
        else q2.push(i);
    }
    while(q.size()&&q2.size()&&-q.top()<q2.top()){
        ans++;q.pop();q2.pop();
    }
    printf("%d\n",ans);
}
int main(){
    // freopen("in.txt","r",stdin);
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}
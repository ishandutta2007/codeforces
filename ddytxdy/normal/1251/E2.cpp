#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+50;
int t,n;LL ans;
vector<int>v[N];
priority_queue<int>q;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);ans=0;for(int i=0;i<=n;i++)v[i].clear();while(q.size())q.pop();
        for(int i=1,x,y;i<=n;i++)scanf("%d%d",&x,&y),v[x].push_back(y);
        for(int i=n;~i;i--){
            for(int x : v[i])q.push(-x);
            while(q.size() > n-i)ans-=q.top(), q.pop();
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
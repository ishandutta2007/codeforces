#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
int n,ans,sum;
priority_queue <int>h;
struct node{
    int a,t;
}a[200005];
bool cmp(node a,node b){
    return a.a<b.a;
}
signed main(){
    cin>>n;
    for (int i=1;i<=n;i++)scanf("%lld",&a[i].a);
    for (int i=1;i<=n;i++)scanf("%lld",&a[i].t);
    sort(a+1,a+1+n,cmp);
    for (int i=1;i<=n;){
        int nowa=a[i].a;
        while(a[i].a==nowa)sum+=a[i].t,h.push(a[i].t),i++;
        nowa++;
        while(!h.empty()){
            sum-=h.top();
            h.pop();
            ans+=sum;
            while(a[i].a==nowa)sum+=a[i].t,h.push(a[i].t),i++;
            nowa++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
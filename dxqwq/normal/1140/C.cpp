#include<bits/stdc++.h>
#include<queue>
using namespace std;
const long long maxn=1e6+9;
struct node{
    long long len,val;
}a[maxn];

bool cmp(node x,node y)
{
    return x.val<y.val;
}

priority_queue<long long,vector<long long>,greater<long long> >que;
long long n,k,ans,sum;
int main()
{
    cin>>n>>k;
    for(long long i=1;i<=n;++i) cin>>a[i].len,cin>>a[i].val;
    sort(a+1,a+1+n,cmp);
    for(long long i=n;i>=1;--i){
        if((n-i+1)<=k) sum+=a[i].len, que.push(a[i].len);
        else{
            if(que.top()<a[i].len){
                sum-=que.top(); que.pop();
                sum+=a[i].len; que.push(a[i].len);
            }
        }
        ans=max(ans,sum*a[i].val);
    }
    cout<<ans;
    return 0;
}
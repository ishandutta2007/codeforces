#include<bits/stdc++.h>

using namespace std;

const int maxn=300005;

struct s{
    int l,b;
};

s x[maxn];
int n,k;
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>x[i].l>>x[i].b;
    }
    sort(x+1,x+1+n,[](s a,s b){return a.b>b.b;});
    priority_queue<int,vector<int>,greater<int> > q;
    long long sm=0,ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,(long long)x[i].b*(x[i].l+sm));
        if(q.size()<k-1){
            q.push(x[i].l);
            sm+=x[i].l;
        }else{
            if(q.empty())continue;
            if(q.top()<x[i].l){
                sm-=q.top();
                q.pop();
                sm+=x[i].l;
                q.push(x[i].l);
            }
        }
    }
    cout<<ans;
    return 0;
}
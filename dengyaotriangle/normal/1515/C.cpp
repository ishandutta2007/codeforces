#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=100005;

int n,m,x;
int ans[maxn];
pair<int,int> b[maxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>x;
        for(int i=1;i<=n;i++)cin>>b[i].first,b[i].second=i;
        sort(b+1,b+1+n);
        priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > > pq;
        for(int i=1;i<m;i++)ans[b[i].second]=i,pq.push({b[i].first,i});
        for(int i=m;i<=n;i++)ans[b[i].second]=m;
        int ct=m,u=0;
        for(int i=m;i<=n;i++)u+=b[i].first;
        while(!pq.empty()&&u-pq.top().first>x){
            int z=pq.top().first,cu=pq.top().second;pq.pop();
            ans[b[ct].second]=cu;
            z+=b[ct].first;u-=b[ct].first;ct++;
            pq.push({z,cu});
        }
        cout<<"YES\n";
        for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
        cout<<'\n';
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int n,a[10],b[100005],ans=1e9,tot;
vector<pair<int,int>> v;
multiset<int> s;
int m[100005],pre[600005],suf[600005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i=1;i<=6;i++)cin>>a[i];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i];
        for(int bs=1;bs<=6;bs++)v.emplace_back(make_pair(b[i]-a[bs],i));
    }
    sort(v.begin(),v.end());
    memset(m,-1,sizeof(m));
    tot=n;
    for(int i=0;i<v.size();i++){
        const pair<int,int> &p=v[i];
        if(m[p.second]!=-1){
            s.erase(s.find(m[p.second]));
        }else tot--;
        s.insert(m[p.second]=p.first);
        if(tot==0)ans=min(ans,p.first-*s.begin());
    }
    cout<<ans<<endl;

    return 0;
}
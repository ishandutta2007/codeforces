#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;


int n;
long long k;
long long a[maxn],b[maxn],g[maxn];
vector<int> v[maxn];

bool chk(long long t){
    for(int i=1;i<=k;i++)v[i].clear();
    for(int i=1;i<=n;i++){
        g[i]=a[i];
        long long est=g[i]/b[i];
        //q.push(make_pair(est,i));
        if(est<=k)v[est+1].push_back(i);
    }
    int pt=1;
    for(int i=1;i<k;i++){
        //pair<int,int> u=q.top();q.pop();
        while(pt<k&&v[pt].size()==0)pt++;
        if(pt>=k)return 1;
        int id=v[pt][v[pt].size()-1];v[pt].pop_back();
        g[id]+=t;
        //q.push(make_pair(g[u.second]/b[u.second],u.second));
        long long est=g[id]/b[id];
        if(est<=k)v[est+1].push_back(id);
        if(v[i].size()!=0) return 0;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    long long l=0,r=0x3fff3fff3fff;
    chk(5);
    while(r-l>3){
        long long m=(l+r)>>1;
        if(chk(m)){
            r=m;
        }else l=m;
    }
    for(long long i=l;i<=r;i++){
        if(chk(i)){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;

    return 0;
}
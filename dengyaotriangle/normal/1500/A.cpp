#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=3005;
const int maxm=2.5e6+4;

int n;
pair<int,int> a[maxn];
pair<int,int> z[maxm*2];

int main(){
    cin>>n;
    n=min(n,3000);
    for(int i=1;i<=n;i++)cin>>a[i].first,a[i].second=i;
    sort(a+1,a+1+n);
    for(int i=4;i<=n;i++)if(a[i].first==a[i-1].first&&a[i].first==a[i-2].first&&a[i].first==a[i-3].first){
        cout<<"YES\n"<<a[i].second<<' '<<a[i-1].second<<' '<<a[i-2].second<<' '<<a[i-3].second<<'\n';return 0;
    }
    pair<int,int> s;int v=0;
    for(int i=2;i<=n;i++)if(a[i].first==a[i-1].first){
        if(a[i-1].first==a[i-2].first)continue;
        pair<int,int> c={a[i].second,a[i-1].second};
        if(v){
            cout<<"YES\n"<<s.first<<' '<<c.first<<' '<<s.second<<' '<<c.second;
            return 0;
        }
        v=a[i].first;s=c;
    }
    if(v)z[v*2]=s;
    n=unique(a+1,a+1+n,[](const pair<int,int>&a,const pair<int,int>&b){return a.first==b.first;})-a-1;
    for(int i=1;i<=n;i++)for(int j=1;j<i;j++){
        int v=a[i].first+a[j].first;
        if(z[v].first){
            cout<<"YES\n"<<z[v].first<<' '<<z[v].second<<' '<<a[i].second<<' '<<a[j].second;return 0;
        }
        z[v]={a[i].second,a[j].second};
    }
    cout<<"NO";
    return 0;
}
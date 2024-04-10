#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=100005;
const int maxm=300005;

int n,m;
long long c[maxn];
 vector<pair<pair<int,int>,long long> > vec;

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,d;
        cin>>u>>v>>d;
        c[u]+=d;c[v]-=d;
    }
    vector<pair<long long,int> > p,m;
    for(int i=1;i<=n;i++){if(c[i]>0)p.push_back(make_pair(c[i],i));}
    for(int i=1;i<=n;i++){if(c[i]<0)m.push_back(make_pair(-c[i],i));}
    sort(p.begin(),p.end());
    sort(m.begin(),m.end());
    int cp1=0,cp2=0;
    while(cp1<p.size()&&cp2<m.size()){
        long long mi=min(p[cp1].first,m[cp2].first);
        vec.push_back(make_pair(make_pair(p[cp1].second,m[cp2].second),mi));
        p[cp1].first-=mi;if(p[cp1].first==0)cp1++;
        m[cp2].first-=mi;if(m[cp2].first==0)cp2++;
    }
    cout<<vec.size()<<endl;
    for(int i=0;i<vec.size();i++){
        cout<<vec[i].first.first<<' '<<vec[i].first.second<<' '<<vec[i].second<<'\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;


int n,m;
struct st{
    long long c,w;
};
vector<long long> v[4];
st a[100005];
vector<pair<long long,int> > q;
long long dp1[300005],dp2[300005],dp3[300005],dp4[300005],dp5[300005];
inline bool cmp(st a,st b){
    return (a.w<b.w || (a.w==b.w && a.c<b.c));
}

inline bool cmp2(pair<long long,int> a,pair<long long,int> b){
    return a.first>b.first || (a.first==b.first && a.second<b.second);
}
inline bool cmp3(long long a,long long b){
    return a>b;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>a[i].w>>a[i].c;
    }
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;++i) {
        v[a[i].w].push_back(a[i].c);
        if (a[i].w==2) q.push_back(make_pair(a[i].c,0));
    }
    for (int i=v[1].size()-2;i>=0;i-=2)
        q.push_back(make_pair(v[1][i]+v[1][i+1],1));
    sort(q.begin(),q.end(),cmp2);
    sort(v[1].begin(),v[1].end(),cmp3);
    for (int i=1;i<=q.size();++i) {
        dp1[i]=dp1[i-1]+q[i-1].first;
        dp2[i]=dp2[i-1]+q[i-1].second;
    }
    ///cout<<"."<<dp1[3]<<"_"<<dp2[3]<<'\n';
    sort(v[3].begin(),v[3].end(),cmp3);
    sort(v[2].begin(),v[2].end(),cmp3);
    long long x=0,y=0;
/*    for (int i=0;i<=v[1].size();++i) {
        y=0;
        for (int j=0;j<=v[2].size();++j) {
            dp4[(i+j*2)]=max(dp4[i+j+j],x+y);
            if (j<v[2].size()) y+=v[2][j];
        }
        if (i<v[1].size()) x+=v[1][i];
    }
*/
    for (int i=0;i<m;++i) {
        int x=dp4[i];
        int y=dp5[i];
        if (x<v[1].size() && dp3[i]+v[1][x]>dp3[i+1]) {
            dp3[i+1]=dp3[i]+v[1][x];
            dp4[i+1]=x+1;
            dp5[i+1]=y;
        }
        if (y<v[2].size() && dp3[i]+v[2][y]>dp3[i+2]) {
            dp3[i+2]=dp3[i]+v[2][y];
            dp4[i+2]=x;
            dp5[i+2]=y+1;
        }
    }
/*    for (int i=1;i<=m;++i)
    if (dp4[i]!=dp3[i]) {
        cout<<i<<"__"<<dp4[i]<<" "<<dp3[i]<<'\n';
    }
*/
    for (int i=1;i<=v[3].size();++i) {
        dp1[i]=dp1[i-1]+v[3][i-1];
    }
    long long ans=0;
    for (int i=0;i<=m;++i) {
        int l=(m-i)/3;
        l=min(l,(int)v[3].size());
        ans=max(ans,dp3[i]+dp1[l]);
    }
    cout<<ans;
}
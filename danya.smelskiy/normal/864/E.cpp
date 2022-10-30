#include <bits/stdc++.h>
using namespace std;
int n;
struct st{
    long long t,d,c;
    int id;
};
st tt[2005];
long long dp[2005][106];
long long ans;
pair<int,int> pred[2005][106];
bool used[2005][106];
int pos1,pos2;
inline bool cmp(st a,st b){
    return a.d<b.d;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>tt[i].t>>tt[i].d>>tt[i].c;
        tt[i].id=i;
    }
    sort(tt+1,tt+n+1,cmp);
    for (int i=0;i<=2000;++i) {
        for (int j=0;j<n;++j) {
            if (dp[i][j+1]<dp[i][j]) {
                used[i][j+1]=false;
                pred[i][j+1]=make_pair(i,j);
                dp[i][j+1]=dp[i][j];
            }
            if (i+tt[j+1].t<tt[j+1].d) {
                long long z=dp[i][j]+tt[j+1].c;
                if (z>dp[i+tt[j+1].t][j+1]) {
                    dp[i+tt[j+1].t][j+1]=z;
                    pred[i+tt[j+1].t][j+1]=make_pair(i,j);
                    used[i+tt[j+1].t][j+1]=true;
                    if (z>ans) {
                    pos1=i+tt[j+1].t;
                    pos2=j+1;
                    ans=z;
                    }
                }
            }
        }
    }
    cout<<ans<<'\n';
   vector<int> ans2;
   while (pos1) {
        if (used[pos1][pos2]) {
            ans2.push_back(pos2);
        }
        int o1,o2;
        o1=pred[pos1][pos2].first;
        o2=pred[pos1][pos2].second;
        pos1=o1;
        pos2=o2;
   }
   cout<<ans2.size()<<'\n';
   reverse(ans2.begin(),ans2.end());
   for (int i=0;i<ans2.size();++i)
    cout<<tt[ans2[i]].id<<" ";
}
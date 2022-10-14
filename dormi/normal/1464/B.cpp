#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
ll suf[MN][2];
ll questioncnt[MN],cnt[MN][2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s;
    cin>>s;
    ll x,y;
    cin>>x>>y;
    int n=sz(s);
    for(int i=n-1;i>=0;i--){
        questioncnt[i]=questioncnt[i+1];
        cnt[i][0]=cnt[i+1][0],cnt[i][1]=cnt[i+1][1];
        if(s[i]=='?'){
            questioncnt[i]++;
            suf[i][0]=suf[i+1][0]+cnt[i][1]*x;
            suf[i][1]=suf[i+1][1]+cnt[i][0]*y;
        }
        else if(s[i]=='0'){
            cnt[i][0]++;
            suf[i][0]=suf[i+1][0]+cnt[i][1]*x;
            suf[i][1]=suf[i+1][1]+(cnt[i][1]+questioncnt[i])*x;
        }
        else{
            cnt[i][1]++;
            suf[i][0]=suf[i+1][0]+(cnt[i][0]+questioncnt[i])*y;
            suf[i][1]=suf[i+1][1]+cnt[i][0]*y;
        }
    }
    ll pre[2]={0,0};
    ll pcnt[2]={0,0};
    ll qcnt=0;
    ll ans=LLONG_MAX;
    for(int i=0;i<n;i++){
        if(s[i]=='?'){
            qcnt++;
            pre[0]+=pcnt[1]*y;
            pre[1]+=pcnt[0]*x;
        }
        else if(s[i]=='0'){
            pcnt[0]++;
            pre[0]+=pcnt[1]*y;
            pre[1]+=(pcnt[1]+qcnt)*y;
        }
        else{
            pcnt[1]++;
            pre[0]+=(pcnt[0]+qcnt)*x;
            pre[1]+=pcnt[0]*x;
        }
        for(int j=0;j<2;j++){
             ans=min(ans,pre[j]+suf[i+1][!j]+(pcnt[j]+qcnt)*(cnt[i+1][!j]+questioncnt[i+1])*(j==0?x:y)+(pcnt[!j])*(cnt[i+1][j])*(j==0?y:x));
        }
    }
    printf("%lli\n",ans);
    return 0;
}
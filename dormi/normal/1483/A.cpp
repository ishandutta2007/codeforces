#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
vector<int> must[MN];
vector<int> can[MN];
int cnt[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m,k,a;
        cin>>n>>m;
        for(int i=1;i<=n;i++)must[i]=vector<int>(),cnt[i]=0;
        for(int i=0;i<m;i++){
            cin>>k;
            can[i]=vector<int>();
            for(int j=0;j<k;j++){
                cin>>a;
                can[i].push_back(a);
                if(k==1)must[a].push_back(i);
            }
        }
        int toomuch=((m+1)/2)+1;
        vector<int> ans;
        for(int i=0;i<m;i++){
            for(auto x:can[i]){
                if(cnt[x]+1+sz(must[x])-(upper_bound(must[x].begin(),must[x].end(),i)-must[x].begin())<toomuch){
                    cnt[x]++;
                    ans.push_back(x);
                    break;
                }
            }
        }
        if(sz(ans)!=m)printf("NO\n");
        else{
            printf("YES\n");
            for(int i=0;i<m;i++)printf("%d%c",ans[i]," \n"[i==m-1]);
        }
    }
    return 0;
}
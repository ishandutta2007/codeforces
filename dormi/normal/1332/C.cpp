#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
pii dsu[MAXN];
int find(int a){
    if(dsu[a].first==a)return a;
    return dsu[a].first=find(dsu[a].first);
}
void uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return;
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp);
    dsu[ap].second+=dsu[bp].second;
    dsu[bp].first=ap;
}
map<char,int> stff[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=0;i<k;i++){
            stff[i].clear();
            dsu[i]={i,1};
        }
        for(int i=0;i<n;i++){
            uni(i%k,(n-i-1)%k);
        }
        string s;
        cin>>s;
        for(int i=0;i<n;i++){
            stff[find(i%k)][s[i]]+=1;
        }
        int ans=0;
        for(int i=0;i<k;i++){
            if(find(i)==i){
                int tot=0;
                int ma=0;
                for(auto x:stff[i]){
                    tot+=x.second;
                    ma=max(ma,x.second);
                }
                ans+=tot-ma;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
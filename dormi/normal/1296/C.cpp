#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
map<pii,int> oc;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        oc.clear();
        int ans=INT_MAX;
        pii ree={-1,-1};
        oc[{0,0}]=0;
        pii cur={0,0};
        char a;
        for(int i=1;i<=n;i++){
            cin>>a;
            if(a=='L')cur.first--;
            else if(a=='R')cur.first++;
            else if(a=='U')cur.second--;
            else if(a=='D')cur.second++;
            if(oc.count(cur)){
                if(i-oc[cur]<ans){
                    ans=i-oc[cur];
                    ree={oc[cur]+1,i};
                }
            }
            oc[cur]=i;
        }
        if(ans==INT_MAX)printf("-1\n");
        else printf("%d %d\n",ree.first,ree.second);
    }
    return 0;
}
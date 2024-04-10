#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
const int MAXC=201;
int am[MAXN][MAXC];
vector<int> locs[MAXC];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a;
        for(int i=1;i<=200;i++)locs[i].clear();
        for(int i=1;i<=n;i++){
            cin>>a;
            locs[a].push_back(i);
            for(int j=1;j<=200;j++){
                am[i][j]=am[i-1][j];
            }
            am[i][a]++;
        }
        int ans=1;
        for(int i=1;i<=200;i++){
            for(int j=0;sz(locs[i])-j-1>j;j++){
                int l=locs[i][j];
                int r=locs[i][sz(locs[i])-j-1];
                for(int k=1;k<=200;k++){
                    ans=max(ans,2*(j+1)+(r-1>=l?am[r-1][k]-am[l][k]:0));
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
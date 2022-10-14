#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
bool onedist[MAXN],twodist[MAXN];
vector<int> matrix[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)onedist[i]=false,twodist[i]=false,matrix[i].clear();
        int a,b;
        for(int i=0;i<m;i++){
            cin>>a>>b;
            matrix[a].push_back(b);
        }
        vector<int> todel;
        for(int i=1;i<=n;i++){
            if(twodist[i])todel.push_back(i);
            else{
                for(int x:matrix[i]){
                    if(onedist[i])twodist[x]=true;
                    else onedist[x]=true;
                }
            }
        }
        assert(sz(todel)<=n*4/7);
        printf("%d\n",sz(todel));
        for(int x:todel)printf("%d ",x);
        printf("\n");
    }
    return 0;
}
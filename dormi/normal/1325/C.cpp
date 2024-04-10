#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
vector<int> matrix[MAXN];
vector<int> edges[MAXN];
int ans[MAXN];
bool done[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        edges[a].push_back(i);
        edges[b].push_back(i);
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(sz(edges[i])==1&&!done[edges[i][0]]){
            ans[edges[i][0]]=cnt;
            cnt++;
            done[edges[i][0]]=true;
        }
    }
    for(int i=1;i<n;i++){
        if(!done[i]){
            ans[i]=cnt;
            cnt++;
            done[i]=true;
        }
        printf("%d\n",ans[i]);
    }
    return 0;
}
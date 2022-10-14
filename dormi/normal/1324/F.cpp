#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
vector<int> matrix[MAXN];
int arr[MAXN];
int dpd[MAXN];
int dpu[MAXN];
int fin[MAXN];
void dfsd(int loc, int parent){
    dpd[loc]=arr[loc];
    for(int x:matrix[loc]){
        if(x!=parent){
            dfsd(x,loc);
            if(dpd[x]>0)dpd[loc]+=dpd[x];
        }
    }
}
void dfsu(int loc, int parent){
    if(loc!=1)dpu[loc]=((dpd[parent]-dpd[loc]+(dpu[parent]>0?dpu[parent]:0)>0&&dpd[parent]+(dpu[parent]>0?dpu[parent]:0)>0)?(dpd[loc]>0?dpd[parent]-dpd[loc]+(dpu[parent]>0?dpu[parent]:0):dpd[parent]+(dpu[parent]>0?dpu[parent]:0)):0);
    int ans=0;
    if(dpu[loc]>0)ans+=dpu[loc];
    fin[loc]=ans+dpd[loc];
    for(int x:matrix[loc])if(x!=parent)dfsu(x,loc);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]==0)arr[i]-=1;
    }
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    dfsd(1,0);
    dfsu(1,0);
    for(int i=1;i<=n;i++)printf("%d ",fin[i]);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
int arr[MAXN];
int fir[MAXN];
priority_queue<pii,vector<pii>,greater<pii>> q;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    set<int> leaves;
    for(int i=1;i<=n;i++)leaves.insert(i),fir[i]=INT_MAX;
    for(int i=1;i<n;i++){
        cin>>arr[i];
        fir[arr[i]]=min(fir[arr[i]],i);
        leaves.erase(arr[i]);
    }
    vector<pii> edges;
    for(int x:leaves){
        q.push({x,x});
    }
    for(int i=n-1;i>=1;i--){
        auto cur=q.top();
        q.pop();
        edges.push_back({cur.second,arr[i]});
        if(i==fir[arr[i]])q.push({max(cur.first,arr[i]),arr[i]});
    }
    printf("%d\n",arr[1]);
    for(auto x:edges)printf("%d %d\n",x.first,x.second);
    return 0;
}
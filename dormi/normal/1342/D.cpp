#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
int am[MAXN];
vector<vector<int>> ans;
vector<int> arrays;
bool work(int si){
    ans.clear();
    ans.resize(si,{});
    priority_queue<pii,vector<pii>,greater<pii>> q;
    for(int i=0;i<si;i++)q.push({0,i});
    for(int i=0;i<sz(arrays);i++){
        auto cur=q.top();
        q.pop();
        if(cur.first+1>am[arrays[i]])return 0;
        ans[cur.second].push_back(arrays[i]);
        q.push({cur.first+1,cur.second});
    }
    return 1;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        arrays.push_back(a);
    }
    sort(arrays.begin(),arrays.end(),greater<>());
    for(int i=1;i<=k;i++){
        cin>>am[i];
    }
    int lo=1,hi=n;
    while(lo!=hi){
        int mid=(lo+hi)/2;
        if(work(mid))hi=mid;
        else lo=mid+1;
    }
    work(lo);
    printf("%d\n",lo);
    for(auto x:ans){
        printf("%d ",sz(x));
        for(auto y:x)printf("%d ",y);
        printf("\n");
    }
    return 0;
}
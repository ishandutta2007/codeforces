#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN=300000;
int arr[MAXN],vote[MAXN];
bool visited[MAXN];
int test(int index,int n){
    fill_n(visited,n,false);
    int ans=0;
    for(int i=0;i<n;++i){
        if(!visited[i]){
            int curr=i;
            do{
                visited[curr]=true;
                curr=arr[(curr+index)%n];
            }while(!visited[curr]);
            ++ans;
        }
    }
    return ans;
}
int32_t main(){
    std::ios_base::sync_with_stdio(false);
    int tc;
    std::cin>>tc;
    for(int ct=0;ct<tc;++ct){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;++i){
            cin>>arr[i];
            --arr[i];
        }
        fill_n(vote,n,0);
        for(int i=0;i<n;++i){
            ++vote[(i+n-arr[i])%n];
        }
        vector<int> ans;
        for(int i=0;i<n;++i){
            if(vote[i]>=n-m*2&&n<=m+test(i,n))ans.push_back(i);
        }
        cout<<ans.size();
        for(int x : ans){
            cout<<' '<<x;
        }
        cout<<'\n';
    }
}
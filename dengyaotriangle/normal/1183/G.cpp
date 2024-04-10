#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

int n;
int cl[maxn],cc[maxn];
vector<int> sz[maxn];

int main(){
    ios::sync_with_stdio(0);
    int q;
    cin>>q;
    while(q--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cl[i]=cc[i]=0;
            sz[i].clear();
        }
        for(int i=1;i<=n;i++){
            int c,t;
            cin>>c>>t;
            cl[c]++;
            if(t) cc[c]++;
        }
        for(int i=1;i<=n;i++){
            sz[cl[i]].push_back(i);
        }
        priority_queue<int> q;
        int ans1=0,ans2=0;
        for(int i=n;i>=1;i--){
            for(int j=0;j<sz[i].size();j++) q.push(cc[sz[i][j]]);
            if(!q.empty()){
                int cur=q.top();q.pop();
                ans1+=i;
                ans2+=min(cur,i);
            }
        }
        cout<<ans1<<' '<<ans2<<'\n';
    }
    return 0;
}
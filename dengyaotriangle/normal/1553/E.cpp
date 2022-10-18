#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=300005;

int n,m;
int p[maxn];
int d[maxn];
int a[maxn];
bool vis[maxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<n;i++)d[i]=0;
        for(int i=1;i<=n;i++)cin>>p[i],d[(i-p[i]+n)%n]++;
        vector<int> ans;
        for(int i=0;i<n;i++)if(d[i]*3>=n){
            for(int j=1;j<=n;j++){
                a[j]=(p[j]+i-1)%n+1;
            }
            int cnt=n;
            for(int j=1;j<=n;j++)vis[j]=0;
            for(int j=1;j<=n;j++){
                if(!vis[j]){
                    cnt--;
                    for(int u=j;!vis[u];u=a[u])vis[u]=1;
                }
            }
            if(cnt<=m)ans.push_back(i);
        }
        cout<<ans.size()<<' ';
        for(int u:ans)cout<<u<<' ';
        cout<<'\n';
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=1000006;
const int maxm=5005;
const int maxl=13;
const int maxls=1<<maxl;

int n;
int a[maxn];
vector<int> p[maxm];
pair<int,int> f[maxls];int fs;
pair<int,int> g[maxls];int gs;
pair<int,int> h[maxls*2];int hs;
int val[maxls];
bool vis[maxls];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],p[a[i]].push_back(i);
    f[0]=make_pair(0,0);fs=1;
    for(int i=0;i<maxm;i++){
        int pt=0;
        for(int j=0;j<maxls;j++)val[j]=INT_MAX;
        for(int j=0;j<fs;j++)val[f[j].second]=f[j].first;
        gs=0;
        for(int j=0;j<fs;j++){
            while(pt<p[i].size()&&p[i][pt]<=f[j].first)pt++;
            if(pt<p[i].size()){
                int u=f[j].second^i;
                g[gs++]=make_pair(p[i][pt],u);
            }
        }
        hs=merge(f,f+fs,g,g+gs,h)-h;
        fs=0;
        for(int i=0;i<hs;i++){
            if(!vis[h[i].second]){
                vis[h[i].second]=1;
                f[fs++]=h[i];
            }
        }
        for(int j=0;j<maxls;j++)vis[j]=0;
    }
    cout<<fs<<'\n';
    for(int i=0;i<fs;i++)vis[f[i].second]=1;
    for(int i=0;i<maxls;i++)if(vis[i])cout<<i<<' ';
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!R

const int maxn=200005;

int n;
int nxt[maxn],c[maxn];
bool vis[maxn];
vector<int> d[maxn];

int main(){
    for(int i=1;i<maxn;i++)for(int j=i;j<maxn;j+=i)d[j].push_back(i);
    ios::sync_with_stdio(0);
    int t;cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){cin>>nxt[i];}
        for(int i=1;i<=n;i++){cin>>c[i];vis[i]=0;}
        int ans=11451411;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                vector<int> s;s.push_back(c[i]);
                vis[i]=1;
                int p=i;while(nxt[p]!=i){p=nxt[p];vis[p]=1;s.push_back(c[p]);}
                for(auto x:d[s.size()]){
                    bool ok=0;
                    if(x==s.size())ok=1;
                    else{
                        for(int p=0;p<x;p++){
                            bool ism=1;
                            for(int q=p+x;q<s.size();q+=x){
                                if(s[q]!=s[q-x]){ism=0;break;}
                            }
                            if(ism){
                                ok=1;break;
                            }
                        }
                    }
                    if(ok){
                        ans=min(ans,x);
                        break;
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
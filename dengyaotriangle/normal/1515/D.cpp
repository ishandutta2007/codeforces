#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=200005;

int n;
int cl[maxn],cr[maxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>n>>l>>r;
        for(int i=1;i<=n;i++)cl[i]=cr[i]=0;
        for(int i=1;i<=l;i++){
            int c;cin>>c;
            cl[c]++;
        }
        for(int i=1;i<=r;i++){
            int c;cin>>c;
            cr[c]++;
        }
        int ans=0,lc=0,rc=0;
        for(int i=1;i<=n;i++){
            int mi=min(cl[i],cr[i]);
            cl[i]-=mi;cr[i]-=mi;
            if(cl[i])lc+=cl[i];
            if(cr[i])rc+=cr[i];
        }
        int v=min(lc,rc);
        ans+=v;
        lc-=v;rc-=v;
        lc/=2;rc/=2;
        ans+=lc+rc;
        for(int i=1;i<=n;i++){
            if(cl[i]){
                lc-=cl[i]/2;
            }
            if(cr[i]){
                rc-=cr[i]/2;
            }
        }
        ans+=max(0,lc)+max(0,rc);
        cout<<ans<<'\n';
    }
    return 0;
}
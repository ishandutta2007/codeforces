#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=1000005;

int n,m,k;
int prv[maxn*2];
bool a[maxn];
int c[maxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a;cin>>a;
        ::a[a]=1;
    }
    if(a[0]){cout<< -1;return 0;}
    prv[0]=0;
    for(int i=1;i<=n+n;i++){
        if(a[i])prv[i]=prv[i-1];
        else prv[i]=i;
    }
    for(int i=1;i<=k;i++)cin>>c[i];
    long long ans=LLONG_MAX;
    for(int i=1;i<=k;i++){
        int cp=0;bool ok=1;
        int cnt=0;
        while(cp<n){
            int nxt=prv[cp+i];
            if(nxt<=cp){ok=0;break;}
            cp=nxt;
            ++cnt;
        }
        if(ok)ans=min(ans,c[i]*(long long)cnt);
    }
    cout<<(ans==LLONG_MAX?-1:ans);
    return 0;
}
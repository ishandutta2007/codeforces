#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=5005;

int n;
int a[maxn];
int ans[maxn];
int id[maxn];
bool vis[maxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    map<int,int> mp;int cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]){
            int t=a[i],res=1;
            if(a[i]<0)res=-1,t=-a[i];
            int wt=t;
            for(int j=2;j*j<=wt;j++){
                if(a[i]%j==0){
                    bool s=0;
                    while(t%j==0){
                        t/=j;s^=1;
                    }
                    if(s)res*=j;
                }
            }
            a[i]=res*t;
            if(!mp.count(a[i])){mp[a[i]]=++cnt;}
            id[i]=mp[a[i]];
        }
    }
    for(int l=1;l<=n;l++){
        int cans=0,h0=0;
        for(int i=0;i<=cnt;i++)vis[i]=0;
        for(int r=l;r<=n;r++){
            if(id[r]){
                cans+=!vis[id[r]];
                vis[id[r]]=1;
            }else{
                h0=1;
            }
            ans[max(cans,h0)]++;
        }
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
    return 0;
}
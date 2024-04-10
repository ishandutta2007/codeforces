#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=200005;

int v[maxn][2];
int cnt[maxn];
int main(){
    memset(v,0x3f,sizeof(v));
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int u,t;cin>>u;t=u;
        for(int i=2;i*i<=u;i++){
            if(t%i==0){
                int c=0;
                while(t%i==0){
                    t/=i;c++;
                }
                int s[3]={v[i][0],v[i][1],c};
                sort(s,s+3);
                v[i][0]=s[0];v[i][1]=s[1];
                cnt[i]++;
            }
        }
        if(t!=1){
            int i=t;
            int s[3]={v[i][0],v[i][1],1};
            sort(s,s+3);
            v[i][0]=s[0];v[i][1]=s[1];
            cnt[i]++;
        }
    }
    long long ans=1;
    for(int i=2;i<maxn;i++){
        if(cnt[i]>=n-1){
            if(cnt[i]==n-1){
                v[i][1]=v[i][0];v[i][0]=0;
            }
            int ex=v[i][1]==0x3f3f3f3f?v[i][0]:v[i][1];
            while(ex--)ans*=i;
        }
    }
    cout<<ans;
    return 0;
}
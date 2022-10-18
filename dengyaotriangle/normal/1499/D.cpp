#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=2e7+10;

bool ntp[maxn];
int prm[maxn],prc;
int ans[maxn];

int calc(int c,int d,int x,int p){
    int uvg=x/p+d;
    if(uvg%c)return 0;
    int uv=uvg/c;
    return ans[uv];
}
int main(){
    ans[1]=1;
    for(int i=2;i<maxn;i++){
        if(!ntp[i]){
            ans[i]=2;
            prm[++prc]=i;
        }
        for(int j=1;i*prm[j]<maxn;j++){
            ntp[i*prm[j]]=1;
            if(i%prm[j]){
                ans[i*prm[j]]=ans[i]*2;
            }else{
                ans[i*prm[j]]=ans[i];
                break;
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
        int c,d,x;
        cin>>c>>d>>x;
        long long ans=0;
        for(int i=1;i*i<=x;i++){
            if(x%i==0){
                ans+=calc(c,d,x,i);
                if(i*i!=x)ans+=calc(c,d,x,x/i);
            }
        }
        cout<<ans<<'\n';
    } 
    return 0;
}
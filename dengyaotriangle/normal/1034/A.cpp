#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=300005;
const int maxt=15000407;

bool ntp[maxt];
vector<int> p;
int n;
int cnt[maxt];
int a[maxn];

void sieve(int n){
    for(int i=2;i<=n;i++){
        if(!ntp[i]){
            p.push_back(i);
            for(int j=i*i;j<=n;j+=i)ntp[j]=1;
        }
    }
}

int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int main(){
    sieve(pow(maxt,0.5));
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int g=0;
    for(int i=1;i<=n;i++)g=gcd(a[i],g);
    for(int i=1;i<=n;i++)a[i]/=g;
    for(int i=1;i<=n;i++){
        for(int j=0;j<p.size();j++){
            if(a[i]%p[j]==0){
                while(a[i]%p[j]==0){
                    a[i]/=p[j];
                }
                cnt[p[j]]++;
            }
        }
        cnt[a[i]]++;
    }
    int ans=n;
    for(int i=2;i<maxt;i++)ans=min(ans,n-cnt[i]);
    if(ans==n)ans=-1;
    cout<<ans;
    return 0;
}
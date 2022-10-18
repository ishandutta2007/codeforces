#include<bits/stdc++.h>

using namespace std;

const int maxn=300005;

int n;
long long c[maxn][3];
long long f[maxn][3];
long long s[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>c[i][1];
    for(int i=1;i<=n;i++)cin>>c[i][2];
    for(int i=n;i>=1;i--)s[i]=s[i+1]+c[i][1]+c[i][2];
    f[n][1]=c[n][2];f[n][2]=c[n][1];
    for(int i=n-1;i>=1;i--){
        f[i][1]=f[i+1][1]+s[i+1]+(2*(n-i)+1)*c[i][2];
        f[i][2]=f[i+1][2]+s[i+1]+(2*(n-i)+1)*c[i][1];
    }
    long long ans=0;
    long long cur1=0,cur2=0;
    for(int i=1;i<=n;i++){
        if(i%2)ans=max(ans,cur1+f[i][1]+2*(i-1)*s[i]);
        else ans=max(ans,cur2+f[i][2]+2*(i-1)*s[i]);
        long long nw1,nw2;
        nw1=cur2+c[i][2]*(i*2-2)+c[i][1]*(i*2-1);
        nw2=cur1+c[i][1]*(i*2-2)+c[i][2]*(i*2-1);
        cur1=nw1;
        cur2=nw2;
    }
    cout<<ans;
    return 0;
}
#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=100005;


int n;
int a[maxn],b[maxn],id[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)id[a[i]]=i;
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++){
        b[i]=id[b[i]];
    }
    int ans=0,mi=0x3fffffff;
    for(int i=n;i>=1;i--){
        if(b[i]>mi)ans++;
        mi=min(mi,b[i]);
    }
    cout<<ans;
    return 0;
}
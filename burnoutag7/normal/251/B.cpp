#include<bits/stdc++.h>
using namespace std;

int n,k,q[105],s[105],p[105],np[105];

int fwd(){
    iota(p+1,p+1+n,1);
    int cnt=0;
    while(memcmp(p+1,s+1,n<<2)&&cnt<=k){
        cnt++;
        for(int i=1;i<=n;i++)np[i]=p[q[i]];
        memcpy(p+1,np+1,n<<2);
    }
    return cnt>k?-1:cnt;
}

int bwd(){
    iota(p+1,p+1+n,1);
    int cnt=0;
    while(memcmp(p+1,s+1,n<<2)&&cnt<=k){
        cnt++;
        for(int i=1;i<=n;i++)np[q[i]]=p[i];
        memcpy(p+1,np+1,n<<2);
    }
    return cnt>k?-1:cnt;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>q[i];
    for(int i=1;i<=n;i++)cin>>s[i];
    int f=fwd(),b=bwd();
    if(f==-1||(k-f&1)||f==0||f==1&&k>f&&b==1)
        if(b==-1||(k-b&1)||b==0||b==1&&k>b&&f==1)cout<<"NO\n";
        else cout<<"YES\n";
    else cout<<"YES\n";

    return 0;
}
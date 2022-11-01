#include<bits/stdc++.h>
using namespace std;

int n,sz,a[300005],cnt[300005],mn;

void mian(){
    cin>>n;
    memset(cnt+1,0,n<<2);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    {
        bool f=true;
        for(int i=1;i<=n;i++)f&=cnt[i];
        cout<<f;
    }
    mn=1;
    while(cnt[mn]==0&&mn<=n)mn++;
    int l=1,r=n,v=1,f=0;
    while(l<=r&&mn==v){
        f=v;
        if(a[l]==v){
            cnt[v]--;
            while(cnt[mn]==0&&mn<=n)mn++;
            l++;v++;
        }else if(a[r]==v){
            cnt[v]--;
            while(cnt[mn]==0&&mn<=n)mn++;
            r--;v++;
        }else break;
    }
    for(int i=2;i<=n;i++){
        cout<<(n+1-i<=f);
    }
    cout<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}
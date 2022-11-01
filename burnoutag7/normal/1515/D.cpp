#include<bits/stdc++.h>
using namespace std;

int n,l,r,c[200005],cnt[200005];

void mian(){
    cin>>n>>l>>r;
    memset(cnt+1,0,n<<2);
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(i<=l){
            cnt[c[i]]++;
        }else{
            cnt[c[i]]--;
        }
    }
    int ans=0,lft=0,rght=0,pl=0,pr=0;
    for(int i=1;i<=n;i++){
        ans+=abs(cnt[i])/2;
        if(cnt[i]>0){
            pl+=abs(cnt[i])/2;
            lft+=cnt[i]%2;
        }else{
            pr+=abs(cnt[i])/2;
            rght+=(-cnt[i])%2;
        }
    }
    int com=min(lft,rght);
    ans+=com;
    lft-=com;
    rght-=com;
    if(lft){
        com=min(lft,pr*2);
        lft-=com;
        ans+=com/2;
        ans+=lft;
    }else{
        com=min(rght,pl*2);
        rght-=com;
        ans+=com/2;
        ans+=rght;
    }
    cout<<ans<<'\n';
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
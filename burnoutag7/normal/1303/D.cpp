#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
int m,a[100005];

int mian(){
    int ans=0;
    map<ll,int> mp;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    for(ll i=1;i<=n;i<<=1){
        if(i&n){
            if(mp[i]){
                mp[i]--;
            }else{
                bool fl=false;
                for(ll j=i<<1,cnt=1;j<=(1ll<<60);j<<=1,cnt++){
                    if(mp[j]){
                        fl=true;
                        ans+=cnt;
                        mp[j]--;
                        j>>=1;
                        while(j>=i){
                            mp[j]++;
                            j>>=1;
                        }
                        break;
                    }
                }
                if(!fl){
                    cout<<-1<<endl;
                    return 0;
                }
            }
        }
        mp[i<<1]+=mp[i]>>1;
    }
    cout<<ans<<endl;
    return 0;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        mian();
    }

    return 0;
}
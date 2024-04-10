#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll sum=k*(k+1)/ll(2);
        string ans;
        for(ll i=0;i<=9;i++){
            for(ll j=1;j<=150;j++){
                if((n-(sum-ll(9)*j*ll(max(ll(0),k+1-(9-i+1)))))%(k+1)==0){
                    ll needed=(n-(sum-ll(9)*j*ll(max(ll(0),k+1-(9-i+1)))))/(k+1);
                    if(needed>=(j-1)*ll(9)+i){
                        needed-=(j-1)*ll(9)+i;
                        string teans;
                        if(ll(9)*j*ll(max(ll(0),k+1-(9-i+1)))==0){
                            int ext=(needed + 8) / ll(9);
                            teans.resize(j + ext);
                            if(needed % ll(9))teans[0] = char('0' + (needed % ll(9)));
                            else teans[0]='9';
                            for (int i = 1; i < ext; i++)teans[i] = '9';
                            for (int l = 0; l < j-1; l++)teans[ext + l] = '9';
                            teans[sz(teans) - 1] = char('0' + i);
                        }
                        else {
                            if (needed == 0) {
                                teans.resize(j);
                                for (int l = 0; l < j - 1; l++)teans[l] = '9';
                                teans[j - 1] = char('0' + i);
                            } else if (needed <= 8) {
                                teans.resize(j + 1);
                                teans[0] = char('0' + needed);
                                for (int l = 1; l <= j - 1; l++)teans[l] = '9';
                                teans[j] = char('0' + i);
                            } else {
                                needed -= 8;
                                int ext = (needed + 8) / ll(9);
                                teans.resize(j + ext+1);
                                if(needed % ll(9))teans[0] = char('0' + (needed % ll(9)));
                                else teans[0]='9';
                                for (int i = 1; i < ext; i++)teans[i] = '9';
                                teans[ext] = '8';
                                for (int l = 1; l < j; l++)teans[ext + l] = '9';
                                teans[sz(teans) - 1] = char('0' + i);
                            }
                        }
                        if(sz(ans)==0)ans=teans;
                        else if(sz(ans)>sz(teans))ans=teans;
                        else if(sz(ans)==sz(teans)&&teans<ans)ans=teans;
                    }
                }
            }
        }
        if(sz(ans)==0)cout<<"-1\n";
        else cout<<ans<<"\n";
    }
    return 0;
}
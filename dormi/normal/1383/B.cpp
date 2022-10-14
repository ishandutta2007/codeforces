#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
int cnt[30];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a;
        for(int i=0;i<30;i++)cnt[i]=0;
        for(int i=0;i<n;i++){
            cin>>a;
            for(int j=0;j<30;j++){
                if(a&(1<<j))cnt[j]++;
            }
        }
        bool done=false;
        for(int i=29;i>=0;i--){
            if(cnt[i]%2){
                done=true;
                if((cnt[i] / 2)%2==0){
                    printf("WIN\n");
                }
                else {
                    int te = (cnt[i] / 2) % 2;
                    if((n - cnt[i]) % 2)te=!te;
                    if (te == 1)printf("LOSE\n");
                    else printf("WIN\n");
                }
                break;
            }
        }
        if(!done)printf("DRAW\n");
    }
    return 0;
}
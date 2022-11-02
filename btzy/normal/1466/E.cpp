#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=500000;
constexpr int MAXEXP=60;
constexpr uint64_t MOD=1000000007;
uint64_t arr[MAXN];
unsigned heightmap[MAXEXP];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc;
    cin>>tc;
    for(int ct=0;ct<tc;++ct){
        int n;
        cin>>n;
        for(int i=0;i<MAXEXP;++i){
            heightmap[i]=0;
        }
        for(int i=0;i<n;++i){
            cin>>arr[i];
            for(int j=0;j<MAXEXP;++j){
                if(arr[i]&(1ull<<j)){
                    ++heightmap[j];
                }
            }
        }
        uint64_t ans=0;
        for(int i=0;i<n;++i){
            uint64_t sum_and=0,sum_or=0;;
            for(int j=0;j<MAXEXP;++j){
                unsigned count_and=((arr[i]&(1ull<<j))?heightmap[j]:0);
                sum_and+=((1ull<<j)%MOD)*count_and;
                sum_and%=MOD;
            }
            for(int j=0;j<MAXEXP;++j){
                unsigned count_or=((arr[i]&(1ull<<j))?static_cast<unsigned>(n):heightmap[j]);
                sum_or+=((1ull<<j)%MOD)*count_or;
                sum_or%=MOD;
            }
            ans+=sum_and*sum_or;
            ans%=MOD;
            /*for(int j=0;j<MAXEXP;++j){
                unsigned count_and=((arr[i]&(1ull<<j))?heightmap[j]:0);
                unsigned count_or=((arr[i]&(1ull<<j))?static_cast<unsigned>(n):heightmap[j]);
                uint64_t tmp=(((1ull<<j)*count_and)%MOD)*(((1ull<<j)*count_or)%MOD);
                ans+=tmp;
                ans%=MOD;
            }*/
        }
        cout<<ans<<'\n';
    }
}
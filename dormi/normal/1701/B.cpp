#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
bool done[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)done[i]=false;
        printf("2\n");
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(!done[i]){
                int cur=i;
                while(cur<=n){
                    done[cur]=true;
                    printf("%d%c",cur," \n"[++cnt==n]);
                    cur*=2;
                }
            }
        }
    }
    return 0;
}
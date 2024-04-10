#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=501;
bitset<501> can[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int a;
    can[0][0]=true;
    for(int i=0;i<n;i++){
        cin>>a;
        for(int j=k;j>=a;j--){
            can[j]|=can[j-a];
            can[j]|=can[j-a]<<a;
        }
    }
    printf("%d\n",can[k].count());
    for(int i=0;i<=k;i++)if(can[k][i])printf("%d ",i);
    return 0;
}
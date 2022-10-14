#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=3e5+1,spin=100;
int arr[MN];
bool gone[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    mt19937_64 gen(time(NULL));
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)cin>>arr[i],arr[i]--;
        uniform_int_distribution<int> rnd(0,n-1);
        set<int> work;
        for(int it=0;it<spin;it++){
            int ind=rnd(gen);
            int offset=(ind-arr[ind]+n)%n;
            for(int i=0;i<n;i++)gone[i]=false;
            int cycles=0;
            for(int i=0;i<n;i++){
                if(!gone[i]){
                    cycles++;
                    int cur=i;
                    while(!gone[cur]){
                        gone[cur]=true;
                        cur=(arr[cur]+offset)%n;
                    }
                }
            }
            if(n-cycles<=m)work.insert(offset);
        }
        printf("%d",sz(work));
        for(auto x:work)printf(" %d",x);
        printf("\n");
    }
    return 0;
}
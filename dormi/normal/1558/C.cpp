#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int SZ(const T &a){return int(a.size());}
const int MN=2022;
int arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool work=true;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            if(arr[i]%2!=i%2){
                work=false;
            }
        }
        if(!work){
            printf("-1\n");
            continue;
        }
        vector<int> moves;
        auto add=[&](int a){
            moves.push_back(a);
            reverse(arr+1,arr+a+1);
        };
        for(int i=n;i>=3;i-=2){
            int loc=0,loc2=0;
            for(int j=1;j<=i;j++){
                if(arr[j]==i)loc=j;
            }
            add(loc);
            for(int j=1;j<=i;j++){
                if(arr[j]==i-1)loc2=j;
            }
            add(loc2-1);
            add(loc2+1);
            add(3);
            add(i);
        }
        assert(is_sorted(arr+1,arr+n+1));
        printf("%d\n",SZ(moves));
        for(int i=0;i<SZ(moves);i++)printf("%d%c",moves[i]," \n"[i==SZ(moves)-1]);
    }
    return 0;
}
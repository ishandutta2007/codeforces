#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=5e4+1;
int arr[MN][5];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int potential=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++){
                cin>>arr[i][j];
            }
            int better=0;
            for(int j=0;j<5;j++){
                better+=arr[i][j]<arr[potential][j];
            }
            if(better>=3)potential=i;
        }
        bool work=true;
        for(int i=0;i<n;i++) {
            if(i!=potential) {
                int better=0;
                for (int j = 0; j < 5; j++) {
                    better+=arr[potential][j]<arr[i][j];
                }
                if(better<3)work=false;
            }
        }
        if(work)printf("%d\n",potential+1);
        else printf("-1\n");
    }
    return 0;
}
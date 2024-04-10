#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=11;
int arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool work=false;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            arr[i]=abs(arr[i]);
            if(arr[i]==0){
                work=true;
            }
        }
        if(work){
            printf("YES\n");
            continue;
        }
        for(int i=1;i<(1<<n);i++){
            int val=0;
            int oth=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    val+=arr[j];
                }
                else oth+=(1<<j);
            }
            for(int m=oth;m>0;m=(m-1)&oth){
                int othsum=0;
                for(int j=0;j<n;j++){
                    if(m&(1<<j)){
                        othsum+=arr[j];
                    }
                }
                if(val==othsum)work=true;
            }
        }
        if(work)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
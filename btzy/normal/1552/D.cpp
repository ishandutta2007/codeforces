#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN=10;
int arr[MAXN];
int32_t main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int ct=0;ct<tc;++ct){
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>arr[i];
        }
        unsigned i;
        for(i=1;i!=(1u<<n);++i){
            unsigned j;
            for(j=i;j!=0u;j=((j-1)&i)){
                int sum=0;
                for(int v=0;v<n;++v){
                    if((1u<<v)&i){
                        if((1u<<v)&j){
                            sum+=arr[v];
                        }
                        else{
                            sum-=arr[v];
                        }
                    }
                }
                if(sum==0){
                    cout<<"YES\n";
                    break;
                }
            }
            if(j!=0u)break;
        }
        if(i==(1u<<n)){
            cout<<"NO\n";
        }
    }
}
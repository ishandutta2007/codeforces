#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
int arr[101];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        if(sum%2==1){
            printf("T\n");
        }
        else {
            bool done=false;
            for (int i = 0; i < n; i++) {
                if(arr[i]>sum/2){
                    printf("T\n");
                    done=true;
                    break;
                }
            }
            if(!done)printf("HL\n");
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int arr[3501];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        k=min(k,m-1);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int ans=0;
        for(int i=0;i<=k;i++){
            int te=INT_MAX;
            for(int j=0;j<=m-1-k;j++){
                te=min(te,max(arr[i+j],arr[n-1-(k-i)-(m-1-k-j)]));
            }
            ans=max(ans,te);
        }
        printf("%d\n",ans);
    }
    return 0;
}
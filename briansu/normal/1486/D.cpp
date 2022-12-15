#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int left=1;
    int right=n;
    int ans=0;
    while(left<=right){
        bool passed=false;
        int mid=(left+right)/2;
        int arr_new[n];
        for(int i=0;i<n;i++){
            if(arr[i]<mid){
                arr_new[i]=-1;
            }else{
                arr_new[i]=1;
            }
        }
        int pfx_sum[n]={};
        int min_sum[n]={};


        pfx_sum[0]=arr_new[0];
        for(int i=1;i<n;i++){
            pfx_sum[i]=pfx_sum[i-1]+arr_new[i];
        }
        min_sum[0]=min(0, pfx_sum[0]);
        for(int i=1;i<n;i++){
            min_sum[i]=min(min_sum[i-1],pfx_sum[i]);
        }
        for(int i=k-1;i<n;i++){
            if(pfx_sum[i]-((i-k<0)?0:min_sum[i-k])>=1){
                left=mid+1;
                ans=mid;
                passed=true;
                break;
            }
        }
        if(passed){
            continue;
        }else{
            right=mid-1;
        }
    }
    cout<<ans;

}
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli arr[(int)1e5+1];
int n;
lli work(lli a){
    lli l=0,h=1e9;
    for(int i=0;i<n;i++){
        if(arr[i]==-1) {
            if(i>0&&arr[i-1]!=-1) {
                l = max(l, arr[i-1] - a);
                h = min(h, arr[i-1] + a);
            }
            if(i<n-1&&arr[i+1]!=-1) {
                l = max(l, arr[i+1] - a);
                h = min(h, arr[i+1] + a);
            }
        }
    }
    if(h>=l)return h;
    return -1;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){

        cin>>n;
        lli te=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(i&&arr[i]!=-1&&arr[i-1]!=-1)te=max(te,abs(arr[i]-arr[i-1]));
        }
        lli lo=te,hi=2e9;
        while(lo!=hi){
            lli mid=(lo+hi)/2;
            if(work(mid)!=-1)hi=mid;
            else lo=mid+1;
        }
        printf("%lli %lli\n",lo,work(lo));
    }
    return 0;
}
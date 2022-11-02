#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=100'000;
pair<int,bool> arr[MAXN*2];
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    long long ans=0;
    for(int i=0;i<n;++i){
        int a,c;
        cin>>a>>c;
        arr[i*2]=make_pair(a,false);
        arr[i*2+1]=make_pair(a+c,true);
        ans+=c;
    }
    sort(arr,arr+2*n);
    int cum=0;
    for(int i=0;i<2*n;++i){
        if(!arr[i].second){
            ++cum;
        }
        else{
            --cum;
            if(cum==0&&i+1<2*n){
                ans+=arr[i+1].first-arr[i].first;
            }
        }
    }
    cout<<ans<<'\n';
}
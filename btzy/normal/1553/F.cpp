#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN=200000;
constexpr int MAXV=300000;
struct fenwick{
    int arr[MAXV+1];
    int query(int i){
        if(i>MAXV)i=MAXV;
        if(i<0)i=0;
        int ret=0;
        for(;i>0;i-=(i&-i)){
            ret+=arr[i];
        }
        return ret;
    }
    void update(int i, int inc){
        for(;i<MAXV+1;i+=(i&-i)){
            arr[i]+=inc;
        }
    }
} fwsum, fwcount;
int arr[MAXN];
int smalls[MAXN];
int* smalls_end=smalls;
bool is_small(int x){
    return x*x<MAXN*4;
    //return x<=0;
}
int32_t main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>arr[i];
        //arr[i]=i+1;
    }
    int curr=0;
    cout<<curr;
    if(is_small(arr[0])){ // small
        *smalls_end++=arr[0];
    }
    else{ // big
        fwcount.update(arr[0],1);
        fwsum.update(arr[0],arr[0]);
    }
    for(int i=1;i<n;++i){
        const int x=arr[i];
        if(is_small(x)){ // small
            for(int j=0;j<i;++j){
                const int y=arr[j];
                curr+=y<x?y:y%x;
                curr+=x<y?x:x%y;
            }
            *smalls_end++=x;
        }
        else{ // big
            for(auto it=smalls;it!=smalls_end;++it){
                const int y=*it;
                curr+=y;
                curr+=x%y;
            }
            for(int z=0;z<=MAXV;z+=arr[i]){
                int sum=fwsum.query(z+arr[i]-1)-fwsum.query(z-1);
                int count=fwcount.query(z+arr[i]-1)-fwcount.query(z-1);
                int offsetsum=sum-count*z;
                //cout<<"V1 "<<sum<<' '<<count<<' '<<offsetsum<<endl;
                curr+=offsetsum;
            }
            {
                int count=fwcount.query(MAXV)-fwcount.query(arr[i]);
                int val=arr[i]*count;
                //cout<<"V3 "<<count<<' '<<val<<endl;
                curr+=val;
            }
            for(int j=1;true;++j){
                int high=arr[i]/j;
                if(is_small(high))break;
                int low=arr[i]/(j+1);
                int sum=fwsum.query(high)-fwsum.query(low);
                int count=fwcount.query(high)-fwcount.query(low);
                int val=arr[i]*count-sum*j;
                //cout<<"V2 "<<sum<<' '<<count<<' '<<val<<endl;
                curr+=val;
            }
            fwcount.update(arr[i],1);
            fwsum.update(arr[i],arr[i]);
        }
        cout<<' '<<curr;
    }
    cout<<'\n';
}
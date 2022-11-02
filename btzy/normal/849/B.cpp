#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000];
unsigned n;
bool flag[1000];
bool test(int grady, int gradx, int intercept){
    for(unsigned i=0;i<n;++i){
        if((long long)grady*i%gradx==0&&arr[i]==(long long)grady*i/gradx+intercept){
            flag[i]=false;
        }
        else{
            flag[i]=true;
        }
        //cout<<flag[i];
    }
    //cout<<endl;
    auto it1=find(flag,flag+n,true);
    if(it1==flag+n)return false;
    long long ic=arr[it1-flag]*gradx-grady*(it1-flag);
    for(unsigned i=0;i<n;++i){
        if(flag[i]&&!(((long long)grady*i+ic)%gradx==0&&((long long)grady*i+ic)/gradx==arr[i])){
            return false;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(unsigned i=0;i<n;++i){
        cin>>arr[i];
    }
    if(test(arr[1]-arr[0],1,arr[0])||test(arr[2]-arr[0],2,arr[0])||test(arr[2]-arr[1],1,arr[1]*2-arr[2])){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
}
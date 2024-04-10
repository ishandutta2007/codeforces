#include<bits/stdc++.h>
using namespace std;
int t,n,x,y;
bool check(int z){
    
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&x,&y);
        // int l=1,r=n,ans=0;
        // while(l<=r){
        //     int mid=(l+r)>>1;
        //     if(check(mid))r=mid-1,ans=mid;
        //     else l=mid+1;
        // }
        cout<<min(max(x+y-n+1,1),n)<<" "<<max(1,min(n,x+y-1))<<endl;
    }
    return 0;
}
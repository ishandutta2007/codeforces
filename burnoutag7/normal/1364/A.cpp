#include<bits/stdc++.h>
using namespace std;

int n,x;
int a[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>n>>x;
        int sum=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(sum%x!=0){
                ans=n-i+1;
                break;
            }
            sum-=a[i];
        }
        sum=0;
        for(int i=1;i<=n;i++){
            sum+=a[i];
        }
        for(int i=n;i>=1;i--){
            if(sum%x!=0){
                ans=max(ans,i);
                break;
            }
            sum-=a[i];
        }
        cout<<ans<<endl;
    }

    return 0;
}
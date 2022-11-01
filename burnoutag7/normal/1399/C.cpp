#include<bits/stdc++.h>
using namespace std;

int n,w[55];

void mian(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    sort(w+1,w+1+n);
    int ans=0;
    for(int k=2;k<=n<<1;k++){
        int l=1,r=n,cur=0;
        while(l<r){
            if(w[l]+w[r]==k){
                cur++;
                l++;
                r--;
            }else
            if(w[l]+w[r]<k){
                l++;
            }else{
                r--;
            }
        }
        ans=max(ans,cur);
    }
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}
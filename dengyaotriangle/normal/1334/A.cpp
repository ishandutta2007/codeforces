#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    ios::sync_with_stdio(0);
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        int l1=0,l2=0;bool ans=1;
        for(int i=1;i<=n;i++){
            int c1,c2;cin>>c1>>c2;
            if(c1<l1||c2<l2||(c2-l2)>(c1-l1))ans=0;
            l1=c1;l2=c2;
        }
        cout<<(ans?"YES\n":"NO\n");
    }
    return 0;
}
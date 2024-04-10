#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int n;
long long l,r;
int main(){
    ios::sync_with_stdio(0);
    int t;cin>>t;
    while(t--){
        cin>>n>>l>>r;
        long long len=0;
        for(int i=1;i<n;i++){
            long long c=2*(n-i);
            if(len+c>=l&&len<=r){
                for(int j=i+1;j<=n;j++){
                    len++;
                    if(len>=l&&len<=r)cout<<i<<' ';
                    len++;
                    if(len>=l&&len<=r)cout<<j<<' ';
                }
            }else len+=c;
        }
        len++;
        if(l<=len&&len<=r)cout<<1;
        cout<<'\n';
    }
    return 0;
}
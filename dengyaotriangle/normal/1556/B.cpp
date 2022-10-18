#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!


int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            a[i]&=1;
        }
        auto calc=[&](bool typ){
            int pos=0;
            long long ret=0;
            for(int i=0;i<n;i++){
                if(a[i]==typ){
                    ret+=abs(i-pos);
                    pos+=2;
                }
            }
            if(pos!=n&&pos!=n+1)return LLONG_MAX;
            return ret;
        };
        long long ans=min(calc(0),calc(1));
        cout<<(ans==LLONG_MAX?-1:ans)<<'\n';
    }
    return 0;
}
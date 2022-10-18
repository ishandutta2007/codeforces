#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        if(accumulate(a.begin(),a.end(),0)==x){
            cout<<"NO\n";
            continue;
        }
        int v=0;
        for(int i=0;i<n;i++){
            v+=a[i];
            if(v==x){
                swap(a[i],a[i+1]);
                break;
            }
        }
        cout<<"YES\n";
        for(int i=0;i<n;i++)cout<<a[i]<<' ';
        cout<<'\n';
    }
    return 0;
}
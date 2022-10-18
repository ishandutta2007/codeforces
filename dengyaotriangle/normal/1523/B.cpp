#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<n*3<<'\n';
        for(int i=0;i<n;i+=2){
            int u=i+1,v=i+2;
            cout<<1<<' '<<u<<' '<<v<<'\n';
            cout<<1<<' '<<u<<' '<<v<<'\n';
            cout<<2<<' '<<u<<' '<<v<<'\n';
            cout<<1<<' '<<u<<' '<<v<<'\n';
            cout<<1<<' '<<u<<' '<<v<<'\n';
            cout<<2<<' '<<u<<' '<<v<<'\n';
        }
    }
    return 0;
}
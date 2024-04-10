#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        if(a[0]+a[1]<=a.back())cout<<"1 2 "<<n<<'\n';
        else cout<<"-1\n";
    }
    return 0;
}
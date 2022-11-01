#include<bits/stdc++.h>
using namespace std;

int t,n;
vector<int> a;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        a.resize(n);
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a.begin(),a.end());
        a.erase(unique(a.begin(),a.end()),a.end());
        cout<<a.size()<<endl;
    }

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        int n,s,t;
        cin>>n>>s>>t;
        int a=s+t-n,b=n-t,c=n-s;
        cout<<max(b,c)+1<<endl;
    }
    return 0;
}
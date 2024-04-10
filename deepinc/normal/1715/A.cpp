#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    int t; cin>>t; while(t--){
        cin>>n>>m; cout<<(n==1&&m==1?0:n+m+min(n,m)-2)<<endl;
    }
}
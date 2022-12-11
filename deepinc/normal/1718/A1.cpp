#include<bits/stdc++.h>
using namespace std;
int n,m,a[123456];
set<int>s;
int main(){
    int t; cin>>t; while(t--){
        cin>>n;
        int S=0,c=0; s.insert(0);
        for(int i=1,x;i<=n;++i){ 
            scanf("%d",&x);
            S^=x; if(s.find(S)!=s.end()) c++,s.clear();
            s.insert(S);
        }cout<<n-c<<endl; s.clear();
        
    }
}
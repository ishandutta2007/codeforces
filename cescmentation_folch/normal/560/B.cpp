#include<bits/stdc++.h>

using namespace std;

int main(){
    int x,y;
    int a[2],b[2];
    cin>>x>>y>>a[0]>>a[1]>>b[0]>>b[1];
    int r = 0;
    for(int i = 0;i <2;++i){
        for(int j = 0;j < 2;++j){
            int k = max(a[(i+1)%2],b[(j+1)%2]);
            if((x >= a[i]+b[j] and y >= k) or (y >= a[i]+b[j] and x >= k)) r = 1;
        }
    }
    if(r) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
}
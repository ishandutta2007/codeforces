#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int q;
        cin>>q;
        if(q%2==1){
            cout<<(q-3)/2+1<<endl;
        }else cout<<q/2<<endl;
    }
    return 0;
}
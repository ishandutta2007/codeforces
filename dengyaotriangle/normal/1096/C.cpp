#include<bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        for(int i=3;i<=720;i++){
            int c=n*i;
            if(c%180) continue;
            if(c/180>i-2||c/180<1) continue;
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
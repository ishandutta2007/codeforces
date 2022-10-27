#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    string s;
    cin>>s;
    if(n!=s.length()){
        cout<<"NO"<<endl;
    }
    else{
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(a[i]==a[j]){
                    if(s[i]!=s[j]){
                        cnt=1;
                        break;
                    }
                }
            }
            if(cnt==1){
                break;
            }
        }
        if(cnt==1){
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
    }}
}
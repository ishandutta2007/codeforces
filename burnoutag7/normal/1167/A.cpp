#include<bits/stdc++.h>
using namespace std;

int T;
int n;
string s;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>n;
        cin>>s;
        bool f=0;
        for(int i=0;i<n;i++){
            if(s[i]=='8'&&n-i>=11){
                f=1;
                break;
            }
        }
        if(f){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
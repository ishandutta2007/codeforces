#include<bits/stdc++.h>
using namespace std;

string s;
int mx;
int pos;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(mx>s[i]){
            cout<<"YES"<<endl;
            cout<<pos+1<<' '<<i+1<<endl;
            return 0;
        }else{
            mx=s[i];
            pos=i;
        }
    }
    cout<<"NO"<<endl;

    return 0;
}
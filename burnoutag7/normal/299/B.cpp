#include<bits/stdc++.h>
using namespace std;

int n,k;
string s;
int cnt;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='#'){
            cnt++;
        }else{
            if(cnt>=k){
                cout<<"NO"<<endl;
                return 0;
            }
            cnt=0;
        }
    }
    if(cnt>=k){
        cout<<"NO"<<endl;
        return 0;
    }else{
        cout<<"YES"<<endl;
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int n,k;
string s,r[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>n>>k;
        cin>>s;
        sort(s.begin(),s.end());
        if(s.front()==s.back()){
            cout<<s.substr(0,(n+k-1)/k)<<endl;
            continue;
        }
        if(s.front()==s[k-1]){
            if(s[k]==s.back()){
                cout<<s.front()+s.substr(k,(n-1)/k)<<endl;
            }else{
                cout<<s.substr(k-1,n-k+1)<<endl;
            }
        }else cout<<s[k-1]<<endl;
    }

    return 0;
}
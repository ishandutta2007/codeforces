#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int main(){
    cin>>s;
    cin>>n;
    if (s.size()%n!=0){
        cout<<"NO";
        return 0;
    }
    n=s.size()/n;
    for (int i=0;i<=s.size()-n;i+=n){
        for (int j=1;j<=n/2;++j){
            if (s[i+j-1]!=s[i+n-j]){
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
}
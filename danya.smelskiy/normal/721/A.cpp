#include <bits/stdc++.h>
using namespace std;
string s;
bool t;
int j,a[100000],n;
int main(){
    cin>>n>>s;

    for (int i=1;i<=n;++i){
        if (s[i-1]=='B' && s[i-2]!='B'){
            ++j;
            a[j]=1;
        } else if (s[i-1]=='B'){
            ++a[j];
        }
    }
    cout<<j<<endl;
    for (int i=1;i<=j;++i){
        cout<<a[i]<<" ";
    }
}
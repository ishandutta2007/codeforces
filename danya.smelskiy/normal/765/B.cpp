#include <bits/stdc++.h>
using namespace std;
bool used[200];
string s;

int main(){
    cin>>s;
    used[0]=true;
    for (int i=0;i<s.size();++i){
        int x=s[i]-'a'+1;
        if (used[x-1]==false) {
            cout<<"NO";
            return 0;
        }
        used[x]=true;
    }
    cout<<"YES";
}
#include<bits/stdc++.h>
using namespace std;

int T;
string s;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>s;
        string a,b;
        for(int i=0;i<s.size();i++){
            if(s[i]%2){
                a+=s[i];
            }else{
                b+=s[i];
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(abs(a[0]-b[b.size()-1])!=1){
            cout<<b+a<<endl;
            continue;
        }
        if(abs(a[a.size()-1]-b[0])!=1){
            cout<<a+b<<endl;
            continue;
        }
        cout<<"No answer"<<endl;
    }

    return 0;
}
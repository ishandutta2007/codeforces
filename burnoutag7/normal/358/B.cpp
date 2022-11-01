#include<bits/stdc++.h>
using namespace std;

int n;
string s,d;
int p;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    s="<3";
    for(int i=0;i<n;i++){
        string t;
        cin>>t;
        s+=t;
        s+="<3";
    }
    cin>>d;
    for(int i=0;i<s.size();i++){
        if(i>=1&&s[i]==s[i-1])p++;
        while(s[i]!=d[p]&&p<d.size()){
            p++;
        }
    }
    if(p<d.size()){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }

    return 0;
}
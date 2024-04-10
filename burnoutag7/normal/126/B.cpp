#include<bits/stdc++.h>
using namespace std;

vector<int> Z(string s){
    int len=s.size(),l=0,r=0;
    vector<int> z(len);
    z[0]=len;
    for(int i=1;i<len;i++){
        if(i>r){
            l=i;r=i-1;
            while(s[r+1]==s[z[i]])r++,z[i]++;
        }else{
            if(i+z[i-l]<=r){
                z[i]=z[i-l];
            }else{
                l=i;
                z[i]=r-i+1;
                while(s[r+1]==s[z[i]])r++,z[i]++;
            }
        }
    }
    return z;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    vector<int> z=Z(s);
    set<int> suf;suf.insert(0);
    int mid=0;
    for(int i=1;i<s.size();i++){
        if(i+z[i]==s.size()){
            suf.insert(z[i]);
        }
        mid=max(mid,min((int)s.size()-1-i,z[i]));
    }
    while(suf.find(mid)==suf.end())mid--;
    if(mid){
        cout<<s.substr(s.size()-mid,mid)<<endl;
    }else{
        cout<<"Just a legend"<<endl;
    }

    return 0;
}
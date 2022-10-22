#include <iostream>
#include <vector>
using namespace std;
string d(string s,string k){
    int b=0;
    vector<int> a;
    for(int i=0;i<s.size();i++){
        for(int o=0;o<k.size();o++){
            if(s[i]==k[o]){
                b=1;
                break;
            }
        }
        if(b==0){
            a.push_back(i);
        }
        b=0;
    }
    for(int i=0;i<a.size();i++){
        s.erase(s.begin()+a[i]-i);
    }
    return s;
}
int main(){
    int n,io,answ=0;
    cin>>n;
    string f="abcdefghijklmnopqrstuvwxyz";
    string a[n];
    char b[n];
    for(int i=0;i<n;i++){
        cin>>b[i]>>a[i];
    }
    for(int i=0;i<n-1;i++){
        if(f.size()==1){
            io=i;
            break;
        }
        if(b[i]=='!'){
            f=d(f,a[i]);
        }else if(b[i]=='.'||b[i]=='?'){
            for(int o=0;o<a[i].size();o++){
                for(int p=0;p<f.size();p++){
                    if(a[i][o]==f[p]){
                        f.erase(f.begin()+p);
                    }
                }
            }
        }
    }
    for(int i=io;i<n-1;i++){
        if(b[i]=='!'||b[i]=='?'){
            answ++;
        }
    }
    cout<<answ;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int c_good(const char *s,const int &len,const char &c){
    if(len==1)return s[0]!=c;
    int pre=0,suf=0;
    for(int i=0;i<len>>1;i++){
        pre+=s[i]!=c;
    }
    for(int i=len>>1;i<len;i++){
        suf+=s[i]!=c;
    }
    return min(pre+c_good(s+(len>>1),len>>1,c+1),c_good(s,len>>1,c+1)+suf);
}

int n;
char s[150005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>n;
        cin>>s;
        cout<<c_good(s,n,'a')<<'\n';
    }

    return 0;
}
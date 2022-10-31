#include <bits/stdc++.h>
using namespace std;
string s,ans;
bool t;
string s1,s2;
int n,i=0;
int main(){
    cin>>n>>s;
    while (i<s.size()){
        s1=""; s2="";
        s1=s[i];
        s1+=s[i+1];
        s2=s1;
        //cout<<s2<<endl;
        s2+=s[i+2];
        if (t==true && s1=="go") i+=2;
        else if (s2=="ogo") { t=true; ans+="***"; i+=3;}
        else { t=false; i++; ans+=s[i-1];}
  //      cout<<i<<" "<<ans<<endl;
    }
    cout<<ans;
}
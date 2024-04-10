#include <bits/stdc++.h>
using namespace std;
string s;
int last,ans;
int main(){
    cin>>s;
    last=0;
    for (int i=0;i<s.size();++i){
 //       cout<<ans<<endl;
        ans+=min(max(s[i]-97,last)-min(s[i]-97,last),min(last+1+25-(s[i]-97),25-last+1+s[i]-97));
        last=s[i]-97;
    }
    cout<<ans;
}
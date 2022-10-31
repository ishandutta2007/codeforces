#include <bits/stdc++.h>
using namespace std;


string s;
int last;
int main(){
    cin>>s;
    s=" "+s+" ";
    for (int i=1;i<s.size()-1;++i)
    if (s[i]==s[i-1]){
        ++last;
        if (last%2==0){
            for (int j=1;j<=26;++j){
                char c=char('a'+j-1);
                if (c!=s[i-1] && c!=s[i+1]) {
                    s[i]=c;
                    break;
                }
            }
        }
    } else last=1;
    s.erase(s.begin());
    s.erase(s.end()-1);
    cout<<s;
}
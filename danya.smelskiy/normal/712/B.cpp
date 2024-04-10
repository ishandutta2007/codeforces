#include <bits/stdc++.h>

using namespace std;
string s;
long long x,up,down,lefter,righter,ans;
int main(){
    cin>>s;
    if (s.length()%2==1){
    cout<<"-1";
    return 0;
    }
    for (int i=0;i<s.size();++i){
        if (s[i]=='L') ++lefter; else if (s[i]=='R') ++righter; else if (s[i]=='U') ++up; else if (s[i]=='D') ++down;
    }
    if ((lefter+righter)%2==1){
        if (lefter<righter) ++lefter;else ++righter;
        if (up>=down) --up; else --down;
        ++ans;
    }
    ans+=abs(lefter-righter)/2;
    ans+=abs(up-down)/2;
    cout<<ans;
}
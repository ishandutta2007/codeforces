#include<bits/stdc++.h>
using namespace std;

string s,t;
int cnt;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    t="1";
    while(t.size()<s.size()||(t.size()==s.size()&&t<s)){
        cnt++;
        t+="00";
    }
    cout<<cnt<<endl;

    return 0;
}
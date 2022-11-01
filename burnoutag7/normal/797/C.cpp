#include<bits/stdc++.h>
using namespace std;

string s,u;
stack<char> t;
char f[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    t.push(char('z'+1));
    f[s.size()-1]=s[s.size()-1];
    for(int i=s.size()-2;i>=0;i--){
        f[i]=min(f[i+1],s[i]);
    }
    for(int i=0;i<s.size();i++){
        while(t.top()<=f[i]&&t.size()>1){
            u+=t.top();
            t.pop();
        }
        t.push(s[i]);
    }
    while(t.size()>1){
        u+=t.top();
        t.pop();
    }
    cout<<u<<endl;

    return 0;
}
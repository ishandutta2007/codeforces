#include<bits/stdc++.h>
using namespace std;

set<string> t;
string n;

void f(int x){
    n[x]++;
    if(n[x]>'9'){
        n[x]='0';
        if(x==0){
            n="1";
            return;
        }
        f(x-1);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    while(t.find(n)==t.end()){
        t.insert(n);
        f(n.size()-1);
        while(n[n.size()-1]=='0'){
            n.erase(n.size()-1,1);
        }
    }
    cout<<t.size()<<endl;

    return 0;
}
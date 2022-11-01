#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n;
    string s;
    cin>>s;
    n=s.size();
    set<char> chs;
    for(char c:s)chs.emplace(c);
    if(chs.size()!=n){
        cout<<"nO\n";
        return;
    }
    if(s.find('a')==s.npos){
        cout<<"nO\n";
        return;
    }
    int l=s.find('a'),r=l;
    for(char c='b';c<='a'+n-1;c++){
        if(s.find(c)==s.npos){
            cout<<"nO\n";
            return;
        }
        int p=s.find(c);
        if(p==l-1)l=p;
        else if(p==r+1)r=p;
        else{
            cout<<"nO\n";
            return;
        }
    }
    cout<<"yEs\n";
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}
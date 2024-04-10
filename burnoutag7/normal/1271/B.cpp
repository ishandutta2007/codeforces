#include<bits/stdc++.h>
using namespace std;

int n;
char s[205];
vector<int> op;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cin>>s+1;
    for(int i=1;i<n;i++){
        if(s[i]=='B'){
            s[i]='W';
            s[i+1]=s[i+1]=='W'?'B':'W';
            op.push_back(i);
        }
    }
    if(s[n]=='W'){
        cout<<op.size()<<endl;
        for(int i=0;i<op.size();i++){
            cout<<op[i]<<' ';
        }
        cout<<endl;
        return 0;
    }
    for(int i=1;i<n;i++){
        if(s[i]=='W'){
            s[i]='B';
            s[i+1]=s[i+1]=='W'?'B':'W';
            op.push_back(i);
        }
    }
    if(s[n]=='B'){
        cout<<op.size()<<endl;
        for(int i=0;i<op.size();i++){
            cout<<op[i]<<' ';
        }
        cout<<endl;
        return 0;
    }
    cout<<-1<<endl;

    return 0;
}
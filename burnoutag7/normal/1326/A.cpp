#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        s.resize(n);
        for(int i=0;i<n;i++)s[i]='2';
        s.back()='3';
        if((n-1)%3==0)s.front()='4';
        cout<<s<<endl;
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
string s;
int stat;
int f[10];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cin>>s;
    for(int i=1;i<=9;i++){
        cin>>f[i];
    }
    for(int i=0;i<n;i++){
        if(stat==0){
            if(f[s[i]-'0']>s[i]-'0'){
                stat=1;
                cout<<f[s[i]-'0'];
            }else{
                cout<<s[i];
            }
            continue;
        }
        if(stat==1){
            if(f[s[i]-'0']<s[i]-'0'){
                stat=2;
                cout<<s[i];
            }else{
                cout<<f[s[i]-'0'];
            }
            continue;
        }
        if(stat==2){
            cout<<s[i];
            continue;
        }
    }

    return 0;
}
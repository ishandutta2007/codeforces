#include<bits/stdc++.h>
using namespace std;

int n,mv;
string s;
int fst,cnt,snd;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cin>>s;
    mv=(n-11)/2;
    for(int i=0;i<s.size();i++){
        if(s[i]=='8'){
            cnt++;
            if(cnt>mv&&mv>=i-cnt+1){
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;

    return 0;
}
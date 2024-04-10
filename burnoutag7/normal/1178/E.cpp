#include<bits/stdc++.h>
using namespace std;

char s[1000005];

void f(int l,int r){
    if(r-l<=3){
        if(r>l)cout<<s[l];
    }else{
        int c[3]={};
        c[s[l]-'a']++;
        c[s[l+1]-'a']++;
        c[s[r-1]-'a']++;
        c[s[r-2]-'a']++;
        for(int i=0;i<3;i++)if(c[i]>1){
            cout<<char('a'+i);
            break;
        }
        f(l+2,r-2);
        for(int i=0;i<3;i++)if(c[i]>1){
            cout<<char('a'+i);
            break;
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    f(0,strlen(s));

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a,b,k;
    cin>>a>>b>>k;
    if(b==1){
        if(k){
            cout<<"No\n";
        }else{
            cout<<"Yes\n";
            cout<<'1';for(int i=1;i<=a;i++)cout<<'0';cout<<'\n';
            cout<<'1';for(int i=1;i<=a;i++)cout<<'0';cout<<'\n';
        }
        return 0;
    }
    if(a==0){
        if(k){
            cout<<"No\n";
        }else{
            cout<<"Yes\n";
            for(int i=1;i<=b;i++)cout<<'1';cout<<'\n';
            for(int i=1;i<=b;i++)cout<<'1';cout<<'\n';
        }
        return 0;
    }
    if(k==0){
        cout<<"Yes\n";
        for(int i=1;i<=b;i++)cout<<'1';for(int i=1;i<=a;i++)cout<<'0';cout<<'\n';
        for(int i=1;i<=b;i++)cout<<'1';for(int i=1;i<=a;i++)cout<<'0';cout<<'\n';
        return 0;
    }
    b--;
    string s[2];
    s[0]+='1';
    s[1]+='1';
    if(a+b-1<k){
        cout<<"No\n";
        return 0;
    }
    cout<<"Yes\n";
    a--;b--;
    s[0]+='1';
    s[1]+='0';
    k--;
    while(k--){
        if(a){
            a--;
            s[0]+='0';
            s[1]+='0';
        }else
        if(b){
            b--;
            s[0]+='1';
            s[1]+='1';
        }else assert(false);
    }
    s[0]+='0';
    s[1]+='1';
    while(a--){
        s[0]+='0';
        s[1]+='0';
    }
    while(b--){
        s[0]+='1';
        s[1]+='1';
    }
    cout<<s[0]<<'\n'<<s[1];

    return 0;
}
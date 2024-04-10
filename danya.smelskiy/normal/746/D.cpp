#include <bits/stdc++.h>
using namespace std;

int f=1,ss=2;
int n,k,x,y,last,lastkol;
string s;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k>>x>>y;
    if (x>=y) last=f;
    else last=ss;
    for (int i=1;i<=n;++i){
        if (x>0 && x>=y && ((last==f && lastkol<k) || (last==ss))){
            --x;
            s+='G';
            if (last==ss){
                last=f;
                lastkol=1;
            } else ++lastkol;
        } else if (y>0 && y>=x && ((last==ss && lastkol<k) || (last==f))){
            --y;
            s+='B';
            if (last==f){
                last=ss;
                lastkol=1;
            } else ++lastkol;
        } else if (x>0 && (last==ss || (last==f && lastkol<k))){
            --x;
            s+='G';
            if (last==ss){
                last=f;
                lastkol=1;
            } else ++lastkol;
        } else if (y>0 && (last==f || (last==ss && lastkol<k))){
            --y;
            s+='B';
            if (last==f){
                last=ss;
                lastkol=1;
            } else ++lastkol;
        } else {
            cout<<"NO";
            return 0;
        }
    }
    cout<<s;
}
#include<bits/stdc++.h>
using namespace std;
#define SZ(X) (X).size()
#define W(X) cout<<X<<endl
int main(){
    string a,b;
    cin>>a>>b;
    for(int i=0;i<SZ(a);i++){
        if(a[i]!='0'){
            a=a.substr(i);
            break;
        }
    }
    if(a[0]=='0')a="0";
    for(int i=0;i<SZ(b);i++){
        if(b[i]!='0'){
            b=b.substr(i);
            break;
        }
    }
    if(b[0]=='0')b="0";
    if(SZ(a)!=SZ(b)){
        if(SZ(a)>SZ(b))W(">");
        else W("<");
    }
    else{
        if(a<b)W("<");
        else if(a>b)W(">");
        else W("=");
    }
}
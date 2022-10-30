#include <bits/stdc++.h>
using namespace std;

string name[100];
string s[100];
string q[100];
int l;
int n,m;
inline string getnew(){
    ++l;
    return q[l];
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=26;++i){
        string k="";
        k+=char('A'-1+i);
        q[i]=k;
        q[26+i]=k+"a";
    }
    for (int i=1;i<=n-m+1;++i){
        cin>>s[i];
    }
    for (int i=n;i>n-m+1;--i)
        name[i]=getnew();
    for (int i=n-m+1;i>0;--i)
        if (s[i]=="YES") name[i]=getnew();
    else name[i]=name[i+m-1];
    for (int i=1;i<=n;++i)
        cout<<name[i]<<" ";
}
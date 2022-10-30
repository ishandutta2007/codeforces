#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int j,n;
string s,s1;
string a[1001];
map<string, string> pred,sonof;
map<string, bool> used;
void add(string s, string s1){
    ++j;
    a[j]=s;
    used[s1]=true;
    pred[s1]=s;
    sonof[s]=s1;
}
void confirm(string s,string s1){
    pred[s1]=pred[s];
    used[s1]=true;
    sonof[pred[s1]]=s1;
}
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>s>>s1;
        if (used[s]==false) add(s,s1);
        else confirm(s,s1);
    }
    cout<<j<<'\n';
    for (int i=1;i<=j;++i){
        cout<<a[i]<<" "<<sonof[a[i]]<<'\n';
    }
}
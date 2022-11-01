#include<bits/stdc++.h>
using namespace std;

int a[18],b[18],c[10],n,m;

void g(int d){
    for(int i=10;--i>=0;)while(c[i]--)a[d++]=i;//   
    assert(d==n);
    for(int i=0;i<n;i++)cout<<a[i];
    cout<<endl;
    exit(0);
}

void f(int d){
    if(d==n){
        for(int i=0;i<n;i++)cout<<a[i];
        cout<<endl;
        exit(0);
    }
    if(c[b[d]]){
        c[b[d]]--;
        a[d]=b[d];
        f(d+1);
        c[b[d]]++;
    }
    for(int i=b[d];--i>=0;){
        if(c[i]){
            c[i]--;
            a[d]=i;
            g(d+1);
            c[i]++;
        }
    }
}

int main(){

    string s;
    cin>>s;
    for(n=0;n<s.size();n++){
        a[n]=s[n]-'0';
        c[a[n]]++;
    }
    cin>>s;
    for(m=0;m<s.size();m++){
        b[m]=s[m]-'0';
    }
    if(n<m){
        g(0);
        return 0;
    }
    f(0);

    return 0;
}
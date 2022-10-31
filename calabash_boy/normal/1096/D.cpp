#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5+5;
char s[N];
long long a,b,c,d,x;
int main(){
    int n;cin>>n>>s;
    for(int i=0;i<n;i++){
        cin>>x;
        if(s[i]=='h') a+=x;
        else if(s[i]=='a') b=min(b+x,a);
        else if(s[i]=='r') c=min(c+x,b);
        else if(s[i]=='d') d=min(d+x,c);
    }
    cout<<d;
}
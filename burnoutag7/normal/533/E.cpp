#include<bits/stdc++.h>
using namespace std;

int n,st,ed;
char s[100005];
char t[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>s+1>>t+1;
    st=1;while(s[st]==t[st])st++;
    ed=n;while(s[ed]==t[ed])ed--;
    bool f1=1;for(int i=st;i<ed;i++)if(s[i]!=t[i+1])f1=0;
    bool f2=1;for(int i=st;i<ed;i++)if(s[i+1]!=t[i])f2=0;
    cout<<f1+f2<<endl;

    return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;
int main() 
{
    int n,d,ans=0;
    string s;
    cin>>n>>d>>s;
    int pos=0;
    while(pos<n-1){
        int i=min(n-1,pos+d);
        while(s[i]=='0')i--;
        if(i==pos){ cout<<-1<<endl; return 0; }
        pos=i;
        ans++;
    }
    cout<<ans<<endl;
}
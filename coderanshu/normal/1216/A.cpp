#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[200002];
    int i,count=0,n;
    cin>>n;
    for(i=0;i<n;i++)cin>>s[i];
    for( i=0;i<n-1;i+=2)
    {
        if(s[i]==s[i+1])
        {
            s[i]=(s[i]=='a')?'b':'a';
            count++;
        }
    }
    cout<<count<<"\n"<<s;
    return 0;
}
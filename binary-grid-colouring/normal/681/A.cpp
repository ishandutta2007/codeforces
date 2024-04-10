#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    string s1;
    int a,b;
    int flag = 0;
    for(int i=0;i<n;i++)
    {
        cin>>s1>>a>>b;
        if(a>=2400&&b>a)
            flag = 1;
    }
    if(flag==1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
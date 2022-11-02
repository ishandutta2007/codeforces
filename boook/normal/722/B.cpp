#include<bits/stdc++.h>
using namespace std;
#define MAX 200
int main()
{
    int x[MAX],t;
    string s;
    while(scanf("%d",&t)==1)
    {
        for(int i=0;i<t;i++)scanf("%d",&x[i]);
        getline(cin,s);
        int q=1;
        for(int i=0;i<t;i++)
        {
            getline(cin,s);
            int ans=0;
            for(int j=0;j<s.size();j++)
            {
                if(s[j]=='a' || s[j]=='e')ans++;
                else if(s[j]=='i' || s[j]=='o')ans++;
                else if(s[j]=='u' || s[j]=='y')ans++;
            }
//            cout<<ans<<endl;
            if(ans!=x[i])q=0;
        }
        if(q)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
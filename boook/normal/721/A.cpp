#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    while(scanf("%d",&t)==1)
    {
        string s;
        cin>>s;s+="W";
        int ans=0,q=0;
        vector<int> v;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='B')q++;
            else if(q!=0)ans++,v.push_back(q),q=0;
        }
        printf("%d\n",ans);
        if(v.size())printf("%d",v[0]);
        for(int i=1;i<v.size();i++)
            printf(" %d",v[i]);
        puts("");
    }
    return 0;
}
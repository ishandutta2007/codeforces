#include<bits/stdc++.h>
using namespace std;
const int maxx=50010;
char s[maxx];
set<pair<long long,int> >st;
int main()
{
    scanf("%s",s);
    long long count=0,ans=0;
    for(int i=0;s[i];i++)
    {
        if(s[i]=='(')count++;
        else if(s[i]==')')count--;
        else
        {
            int a,b;
            cin>>a>>b;
            ans+=b;
            s[i]=')';
            count--;
            st.insert(make_pair(a-b,i));
        }
        while(count<0)
        {
            if(st.empty())return 0*printf("-1");
            ans+=st.begin()->first;
            s[st.begin()->second]='(';
            st.erase(st.begin());
            count+=2;
        }
    }
    if(count>0)printf("-1");
    else printf("%lld\n%s",ans,s);
    return 0;
}
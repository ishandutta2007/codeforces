#include<bits/stdc++.h>
using namespace std;

priority_queue < int , vector < int > , greater < int > > Q;
vector<pair<char,int> >ans;
char s[444];
int main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int p;
        scanf("%s",s);
        if(s[0]!='r')cin>>p;
        if(s[0]=='i')
        {
            Q.push(p);
            ans.push_back(make_pair(s[0],p));
        }
        else if(s[0]=='r')
        {
            if(Q.empty())
            {
                Q.push(1);
                ans.push_back(make_pair('i',1));
            }
            Q.pop();
            ans.push_back(make_pair('r',0));
        }
        else if(s[0]=='g')
        {
            while(!Q.empty())
            {
                int t = Q.top();
                if(t<p)
                {
                    Q.pop();
                    ans.push_back(make_pair('r',0));
                }
                else break;
            }
            if(Q.empty()||Q.top()>p)
            {
                Q.push(p);
                ans.push_back(make_pair('i',p));
            }
            ans.push_back(make_pair('g',p));
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i].first=='r')printf("removeMin ");
        if(ans[i].first=='i')printf("insert ");
        if(ans[i].first=='g')printf("getMin ");
        if(ans[i].first!='r')printf("%d",ans[i].second);
        printf("\n");
    }
}
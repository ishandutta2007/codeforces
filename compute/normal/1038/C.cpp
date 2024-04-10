#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        priority_queue<int,vector<int>,less<int> > A,B;
        for(int i=0,temp;i<n;i++)
        {
            scanf("%d",&temp);
            A.push(temp);
        }
        for(int i=0,temp;i<n;i++)
        {
            scanf("%d",&temp);
            B.push(temp);
        }
        long long sa=0,sb=0;
        while(n--)
        {
            if((!A.empty()&&A.top()>B.top())||B.empty())
            {
                sa+=A.top();
                A.pop();
            }
            else {
                B.pop();
            }
            if((!B.empty()&&A.top()<B.top())||A.empty())
            {
                sb+=B.top();
                B.pop();
            }
            else {
                A.pop();
            }
        }
        printf("%lld\n",sa-sb);
    }
    return 0;
}
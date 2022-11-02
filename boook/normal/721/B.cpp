#include<bits/stdc++.h>
using namespace std;
#define MAX 120
int x[MAX],n,m;
int F(int y)
{
    int w=(y-1)/m;
    return y+w*5;
}
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        memset(x,0,sizeof x);
        string s;
        while(n--)
        {
            cin>>s;
            x[s.length()]++;
        }
        cin>>s;int l=s.length(),q=0;
        for(int i=0;i<l;i++)q+=x[i];
        printf("%d %d\n",F(q+1),F(q+x[l]));
    }
    return 0;
}
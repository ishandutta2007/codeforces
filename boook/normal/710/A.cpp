#include<bits/stdc++.h>
using namespace std;
#define MAX 500000
int n[MAX];
int main()
{
    string s;
    while(cin>>s)
    {
        int ans=0;
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                if(i==j && i==0)continue;
                if(s[0]+i>='a' && s[0]+i<='h' && s[1]+j>='1'&& s[1]+j<='8')
                    ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
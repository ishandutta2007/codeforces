#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    long int n,m=-2000000000,M=2000000000,num,i;
    cin>>n;
    char s[4],a;
    for(i=0;i<n;i++)
    {
        cin>>s>>num>>a;
        if(a=='Y')
        {
            if(s[0]=='>')
            {
                if(s[1]=='=')
                {
                    m=max(m,num);
                }
                else m=max(m,num+1);
            }
             if(s[0]=='<')
            {
                if(s[1]=='=')
                {
                    M=min(M,num);
                }
                else M=min(M,num-1);
            }
        }
        if(a=='N')
        {
             if(s[0]=='>')
            {
                if(s[1]=='=')
                {
                    M=min(M,num-1);
                }
                else M=min(M,num);
            }
             if(s[0]=='<')
            {
                if(s[1]=='=')
                {
                    m=max(m,num+1);
                }
                else m=max(m,num);
            }
        }
    }
    if(M>=m)
    cout<<m;
    else cout<<"Impossible";
    
    return 0;
}
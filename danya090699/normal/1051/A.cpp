#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        string s;
        cin>>s;
        int n=s.size(), q[3]={0, 0, 0};
        char an[n];
        for(int a=0; a<n; a++)
        {
            an[a]=s[a];
            if(s[a]>='a' and s[a]<='z') q[0]++;
            if(s[a]>='A' and s[a]<='Z') q[1]++;
            if(s[a]>='0' and s[a]<='9') q[2]++;
        }
        bool fo=0;
        for(int a=0; a<3; a++)
        {
            if(q[a]==n)
            {
                if(a==0) an[0]='A', an[1]='0';
                if(a==1) an[0]='a', an[1]='0';
                if(a==2) an[0]='a', an[1]='A';
                fo=1;
                break;
            }
        }
        if(fo==0)
        {
            for(int a=0; a<3; a++)
            {
                if(q[a]==0)
                {
                    for(int b=0; b<n; b++)
                    {
                        int ty;
                        if(s[b]>='a' and s[b]<='z') ty=0;
                        if(s[b]>='A' and s[b]<='Z') ty=1;
                        if(s[b]>='0' and s[b]<='9') ty=2;
                        if(q[ty]>1)
                        {
                            if(a==0) an[b]='a';
                            if(a==1) an[b]='A';
                            if(a==2) an[b]='0';
                            break;
                        }
                    }
                }
            }
        }
        for(int a=0; a<n; a++) cout<<an[a];
        cout<<"\n";
    }
}
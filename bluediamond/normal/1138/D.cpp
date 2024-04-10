#include <bits/stdc++.h>

using namespace std;

int f[2];

bool pot(string s)
{
        int n0=0,n1=0;
        for(auto &ch:s)
        {
                if(ch=='0')
                {
                        n0++;
                }
                else
                {
                        n1++;
                }
        }
        if(n0<=f[0] && n1<=f[1])
        {
                f[0]-=n0;
                f[1]-=n1;
                cout<<s;
                return 1;
        }
        else
        {
                return 0;
        }
}

int pr[500000+7];

int kmp(string s)
{
        int p=1,cur=0;
        pr[0]=0;
        while(p<s.size())
        {
                if(s[p]==s[cur])
                {
                        cur++;
                        pr[p]=cur;
                        p++;
                }
                else
                {
                        if(cur==0)
                        {
                                p++;
                        }
                        else
                        {
                                cur=pr[cur-1];
                        }
                }
        }
        return pr[s.size()-1];
}

int main()
{
        string s,t;
        int n,m;
        cin>>s>>t;
        for(auto &ch:s)
        {
                f[ch-'0']++;
        }
        n=s.size();
        m=t.size();
        int p=kmp(t);
        string myt;
        for(int i=p;i<m;i++)
        {
                myt+=t[i];
        }
        pot(t);
        while(pot(myt))
        {

        }
        while(pot("0"))
        {

        }
        while(pot("1"))
        {

        }
        cout<<"\n";
}
/**


**/
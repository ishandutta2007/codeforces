//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=1e6;
bool us2[sz];
string to_str(int x)
{
    string re;
    int st=1e5;
    for(int a=5; a>=0; a--)
    {
        re.push_back('0'+x/st);
        x=x%st, st/=10;
    }
    return re;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, e=0;
    cin>>n;
    bool us[n+1], ar[n];
    string na[n];
    vector <int> bad[2], av[2];
    vector <string> good[2];
    for(int a=1; a<=n; a++) us[a]=0;
    for(int a=0; a<n; a++)
    {
        cin>>na[a]>>ar[a];
        e+=ar[a];
    }
    for(int a=0; a<n; a++)
    {
        string s=na[a];
        int x=ar[a], va=0;
        for(int b=0; b<s.size(); b++)
        {
            if(s[b]>='0' and s[b]<='9') va=va*10+(s[b]-'0');
            else
            {
                va=-1;
                break;
            }
        }
        if(va!=-1) us2[va]=1;
        if(s[0]=='0') va=-1;
        if(va!=-1)
        {
            if(va>n) va=-1;
        }
        if(va!=-1)
        {
            if(x==0 and va<=e) bad[0].push_back(va);
            else if(x==1 and va>e) bad[1].push_back(va);
            us[va]=1;
        }
        else good[x].push_back(s);
    }
    for(int a=1; a<=e; a++) if(us[a]==0) av[1].push_back(a);
    for(int a=e+1; a<=n; a++) if(us[a]==0) av[0].push_back(a);
    int q=bad[1].size()+bad[0].size()+good[1].size()+good[0].size();
    if(q>0)
    {
        if(av[1].size()==0 and av[0].size()==0)
        {
            int x;
            for(int a=1; a<sz; a++)
            {
                if(us[a]==0)
                {
                    x=a;
                    break;
                }
            }
            cout<<q+1<<"\n";
            cout<<"move "<<bad[1].back()<<" "<<to_str(x)<<"\n";
            good[1].push_back(to_str(x)), av[0].push_back(bad[1].back());
            bad[1].pop_back();
        }
        else cout<<q<<"\n";
        for(int a=0; a<q; a++)
        {
            cout<<"move ";
            if(av[1].size()>0)
            {
                if(bad[1].size()>0)
                {
                    cout<<bad[1].back()<<" "<<av[1].back();
                    av[0].push_back(bad[1].back());
                    bad[1].pop_back();
                }
                else
                {
                    cout<<good[1].back()<<" "<<av[1].back();
                    good[1].pop_back();
                }
                av[1].pop_back();
            }
            else
            {
                if(bad[0].size()>0)
                {
                    cout<<bad[0].back()<<" "<<av[0].back();
                    av[1].push_back(bad[0].back());
                    bad[0].pop_back();
                }
                else
                {
                    cout<<good[0].back()<<" "<<av[0].back();
                    good[0].pop_back();
                }
                av[0].pop_back();
            }
            cout<<"\n";
        }
    }
    else cout<<0;
}
#include <bits/stdc++.h>

using namespace std;

bool rule1(char a,char b)
{
          a=toupper(a);
          b=toupper(b);
          return a==b;
}

bool rule2(char a,char b)
{
          if(a=='0' && b=='O')
                    return 1;
          if(b=='0' && a=='O')
                    return 1;
          if(a=='0' && b=='o')
                    return 1;
          if(b=='0' && a=='o')
                    return 1;

          return 0;
}

bool rule3(char a,char b)
{
          bool ok1=(a=='l' || a=='L' || a=='1' || a=='i' || a=='I');
          bool ok2=(b=='l' || b=='L' || b=='1' || b=='i' || b=='I');

          return (ok1 && ok2);
}

string s,cur;
int n;

int main()
{
          cin>>s;
          cin>>n;
          for(int i=0;i<n;i++)
          {
                    cin>>cur;
                    if(cur.size()!=s.size()) continue;
                    bool same=1;
                    for(int j=0;j<cur.size();j++)
                    {
                              bool ok=(cur[j]==s[j]);
                              ok|=rule1(cur[j],s[j]);
                              ok|=rule2(cur[j],s[j]);
                              ok|=rule3(cur[j],s[j]);
                              same&=ok;
                    }
                    if(same)
                    {
                              cout<<"No";
                              return 0;
                    }
          }
          cout<<"Yes";
}
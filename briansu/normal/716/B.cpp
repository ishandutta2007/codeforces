#include <cmath>
#include <iostream>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>
#include <map>
#include <iomanip>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int l=s.length();
    if(l<26){cout<<-1<<endl;return 0;}
    int q=0;
    int cnt[26];
    memset(cnt,0,sizeof(cnt));
    set<char> c;
    for(int i=0;i<l;i++)
    {
        if(i>=26)
        {
            if(s[i-26]=='?')q--;
            else
            {

                if((--cnt[s[i-26]-'A'])==0) c.erase(s[i-26]);
            }
        }
        if(s[i]=='?')q++;
        else if((++cnt[s[i]-'A'])==1) c.insert(s[i]);
        if(c.size()+q==26)
        {
            int nc=0;
            for(int j=i-25;q>0;j++)
            {
                if(s[j]=='?')
                {
                    while(c.count('A'+nc))nc++;
                    s[j]='A'+nc;
                    nc++;
                    q--;
                }
            }
            for(int j=0;j<l;j++)
            {
                if(s[j]=='?')s[j]='A';
            }
            cout<<s<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}
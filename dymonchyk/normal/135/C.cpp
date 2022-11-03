#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

char str[100005];

vector <string> check()
{
    string s(str);
    int n=0;
    vector <string> ret;
    for(int i=0;i<s.size();i++)
        if (s[i]=='?') n++;
    for(int mask=0;mask<(1<<n);mask++)
    {
        int k=mask;
        string ss="";
        for(int i=0;i<s.size();i++)
        {
            if (s[i]!='?') ss+=s[i];
            else ss+=(char)((k&1)+'0'),k>>=1;
        }
        string tmp=ss;
        while(ss.size()>2)
        {
            bool ok=false;
            for(int i=0;i<ss.size();i++)
            {
                if (ss[i]=='1')
                {
                    ss.erase(ss.begin()+i);
                    ok=true;
                    break;
                }
            }
            if (!ok) ss.erase(ss.end());
            if (ss.size()==2) break;
            ok=false;
            for(int i=0;i<ss.size();i++)
            {
                if (ss[i]=='0')
                {
                    ss.erase(ss.begin()+i);
                    ok=true;
                    break;
                }
            }
            if (!ok) ss.erase(ss.end());
        }
        ret.push_back(ss);
//      if (ss=="01") cout << tmp << endl;
    }
    return ret;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    gets(str);
    int n=strlen(str),zero=(n-2)/2,one=(n-1)/2;
    for(int mask=0;mask<4;mask++)
    {
        int pos0=-1,pos1=-1;
        for(int i=n-1;i>=0;i--)
        {
            if (str[i]=='?'||str[i]==((mask&1)+'0'))
            {
                pos0=i;
                break;
            }
        }
        for(int i=pos0-1;i>=0;i--)
        {
            if (str[i]=='?'||str[i]==(((mask&2)>>1)+'0'))
            {
                pos1=i;
                break;
            }
        }
//      if (pos0!=n-1) continue;
        if (mask==0&&pos1!=-1&&pos0!=-1)
        {
            int cz=0;
            for(int i=0;i<pos1;i++)
                if (str[i]=='?'||str[i]=='0') cz++;
            if (cz>=zero)
            {
                cout << "00" << endl;
//              nans+="00";
            }
        } else
        if (mask==3&&pos1!=-1&&pos0!=-1)
        {
            int cz=0;
            for(int i=0;i<pos1;i++)
                if (str[i]=='?'||str[i]=='1') cz++;
            if (cz>=one)
            {
                cout << "11" << endl;
//              nans+="11";
            }
        } else
        if (mask==2&&pos1!=-1&&pos0!=-1)
        {
            int co=0,cc=0,lone=-1;
            for(int i=n-1;i>=0;i--)
                if (str[i]=='1')
                {
                    lone=i;
                    break;
                }
            for(int i=0;i<lone;i++)
            {
                if (str[i]=='1') co++;
                if (str[i]=='?') cc++;
            }
            if (co<=one)
            {
                for(int i=lone;i<n;i++)
                {
                    if (co+cc>=one)
                    {
                        bool ok1=false,ok2=false;
                        for(;i<n;i++)
                        {
                            if (str[i]=='1'||str[i]=='?')
                            {
                                ok1=true;
                                i++;
                                break;
                            }
                        }
                        for(;i<n;i++)
                        {
                            if (str[i]=='0'||str[i]=='?')
                            {
                                ok2=true;
                                i++;
                                break;
                            }
                        }
                        if (ok1&&ok2) cout << "10\n";
                        break;
                    }
                    if (str[i]=='1'||str[i]=='?') co++;
                }
            }
        } else
            if (mask==1&&pos1!=-1&&pos0!=-1)
        {
            int co=0,cc=0,lone=-1;
            for(int i=n-1;i>=0;i--)
                if (str[i]=='0')
                {
                    lone=i;
                    break;
                }
            for(int i=0;i<lone;i++)
            {
                if (str[i]=='0') co++;
                if (str[i]=='?') cc++;
            }
            if (co<=zero)
            {
                for(int i=lone;i<n;i++)
                {
                    if (co+cc>=zero)
                    {
                        bool ok1=false,ok2=false;
                        for(;i<n;i++)
                        {
                            if (str[i]=='0'||str[i]=='?')
                            {
                                ok1=true;
                                i++;
                                break;
                            }
                        }
                        for(;i<n;i++)
                        {
                            if (str[i]=='1'||str[i]=='?')
                            {
                                ok2=true;
                                i++;
                                break;
                            }
                        }
                        if (ok1&&ok2) cout << "01\n";
                        break;
                    }
                    if (str[i]=='0'||str[i]=='?') co++;
                }
            }
        }
    }
    return 0;
}
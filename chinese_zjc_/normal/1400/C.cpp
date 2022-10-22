//This Code was made by Chinese_zjc_.
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#include<time.h>
// #include<windows.h>
#define int long long
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
int t,x;
string s,w;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>s>>x;
        s=s;
        w.assign(s.length(),'1');
        for(int i=0;i<(int)s.length();++i)
        {
            if(s[i]=='0')
            {
                if(i>=x)
                {
                    w[i-x]='0';
                }
                if(i+x<(int)w.length())
                {
                    w[i+x]='0';
                }
            }
        }
        for(int i=0;i<(int)s.length();++i)
        {
            if(s[i]=='1'&&!((i>=x&&w[i-x]=='1')||(i+x<(int)w.length()&&w[i+x]=='1')))
            {
                w="-1";
                break;
            }
        }
        cout<<w<<endl;
    }
    return 0;
}
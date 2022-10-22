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
int n,a[105],cnt,ans;
string s;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>s;
        s=' '+s;
        cnt=0;
        for(int j=1;j<(int)s.length();++j)
        {
            if(s[j]=='1')
            {
                a[++cnt]=1;
                while(++j<(int)s.length()&&s[j]=='1')
                {
                    ++a[cnt];
                }
            }
        }
        sort(a+1,a+1+cnt);
        ans=0;
        for(int i=cnt;i>0;i-=2)
        {
            ans+=a[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
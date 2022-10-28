#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define N 100005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef unsigned long long LL;
typedef pair<int,int> pii;
pair<LL,LL> ans;
void Print(pair<LL,LL> ans)
{
    LL gcd=__gcd(ans.fi,ans.se);
    cout<<ans.fi/gcd<<"/"<<ans.se/gcd<<endl;
}
int main()
{
    unsigned long long t,w,b,gcd,lcm;
    double tt,tw,tb,tlcm,tgcd;
    cin>>t>>w>>b;
    gcd=__gcd(w,b);
    tt=t,tw=w,tb=b,tgcd=gcd;
    tlcm=tw/tgcd*tb;
    if(tlcm>tt*1.5)
    {
        ans.fi=min(t,min(w,b)-1);
        ans.se=t;
        //debug(1);
        Print(ans);
    }
    else
    {
        lcm=w/gcd*b;
        //debug(lcm);
        ans.fi=min(w,b)*(t/lcm)+min(min(w,b),(t)%lcm+1)-1;
        ans.se=t;
        Print(ans);
    }
    return 0;

}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))
/*
1 9 9

370330636048898430 61721772674816405 6
*/
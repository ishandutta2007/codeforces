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
typedef long long LL;
typedef pair<int,int> pii;
char op[2];
multiset<int> tw,th;
set<int> dw,dh;
int main()
{
    LL w,h;
    int n,i,l,tl,tr,nw,nh;
    multiset<int>::iterator it;
    cin>>w>>h>>n;
    tw.insert(w);
    th.insert(h);
    dw.insert(0);
    dw.insert(w);
    dh.insert(0);
    dh.insert(h);
    nw=w,nh=h;
    while(n--)
    {
        scanf("%s",op);
        scanf("%d",&l);
        if(op[0]=='V')
        {
            it=dw.upper_bound(l);
            tr=*(it);
            tl=*(--it);
            dw.insert(l);
            tw.erase(tw.find(tr-tl));
            tw.insert(tr-l);
            tw.insert(l-tl);
            nw=*tw.rbegin();
        }
        else
        {
            it=dh.upper_bound(l);
            tr=*(it);
            tl=*(--it);
            dh.insert(l);
            th.erase(th.find(tr-tl));
            th.insert(tr-l);
            th.insert(l-tl);
            nh=*th.rbegin();
        }
        printf("%I64d\n",(LL)nh*nw);
    }
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
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
#include<iomanip>
#include<deque>
#include<utility>
#define INF 1000000000
#define fi first
#define se second
#define N 100005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
char s[25];
int num[200];
int main()
{
    int m,i;
    num['f']=1;
    num['e']=2;
    num['d']=3;
    num['a']=4;
    num['b']=5;
    num['c']=6;
    unsigned long long n=0,ans=0;
    scanf("%s",s+1);
    m=strlen(s+1);
    for(i=1;i<m;i++)
    {
        n=n*10+s[i]-48;
    }
    ans+=(n-1)/4*16;
    if(n%2==0)
        ans+=7;
    ans+=num[s[m]];
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/
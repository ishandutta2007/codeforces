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
int day[13]={31,28,30};
string s[10]={ "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
int main()
{
    string d1,d2;
    int x,y,i,flag=0;
    //scanf("%s%s",d1,d2);
    cin>>d1>>d2;
    for(x=0;x<7;x++)
        if(d1==s[x])
            break;
    for(y=0;y<7;y++)
        if(d2==s[y])
            break;
    //debug9x)
    for(i=0;i<=2;i++)
        if((x+day[i])%7==y)
            flag=1;
    if(flag)
        printf("YES\n");
    else printf("NO\n");
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/
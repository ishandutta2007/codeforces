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
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
map<char,int> mp;
int main()
{
    mp['Q']=9;
    mp['q']=-9;
    mp['R']=5;
    mp['r']=-5;
    mp['B']=3;
    mp['b']=-3;
    mp['N']=3;
    mp['n']=-3;
    mp['P']=1;
    mp['p']=-1;
    char t;
    int ans=0;
    while(cin>>t)
        ans+=mp[t];
    if(ans>0)
        printf("White\n");
    else if(ans<0)
        printf("Black\n");
    else printf("Draw\n");
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
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
int main()
{
    string s1,s2,t1,t2;
    int n,i;
    cin>>s1>>s2;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cout<<s1<<' '<<s2<<endl;
        cin>>t1>>t2;
        if(t1==s1)
        {
            s1=t2;
        }
        else s2=t2;
    }
    cout<<s1<<' '<<s2<<endl;
    return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/
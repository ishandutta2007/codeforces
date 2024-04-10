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
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        LL n, m, pw;
        cin >> n;
        m = n;
        while(m % 2 == 0)
        {
            m /= 2;
        }
        pw = n / m;
        if(pw*2 +1 > m && m!=1)
        {
            cout<<m<<endl;
        }
        else if(m!=1)
        {
            cout << pw*2 <<endl;
        }
        else
            cout << -1 << endl;
    }
}
// davidlee1999WTK 2022/
// Team NewType, UT Austin
// srO myk Orz
//ios::sync_with_stdio(false);
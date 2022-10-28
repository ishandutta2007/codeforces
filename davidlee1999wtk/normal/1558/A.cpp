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
#define N 200005
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
        int a, b, m;
        cin >> a >> b;
        m = (a+b);
        if(a < b) swap(a,b);
        int l = a - (m+1)/2;
        int r = b + (m+1) / 2;
        int op = (m % 2 == 0) ? 2 : 1;
        if(op == 1)
            cout<<r-l+1<<endl;
        else
            cout<<(r-l+2)/op<<endl;
        for(int i=l;i<=r;i+= op)
            printf("%d ", i);
        cout<<endl;
    }
}
// davidlee1999WTK 2022/
// Team NewType, UT Austin
// srO myk Orz
//ios::sync_with_stdio(false);
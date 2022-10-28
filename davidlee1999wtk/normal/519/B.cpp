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
multiset<int> s1,s2;
int main()
{
    int n,a,i;
    cin>>n;
    for(i=1;i<=n;i++)
        scanf("%d",&a),s1.insert(a);
    for(i=1;i<n;i++)
        scanf("%d",&a),s1.erase(s1.lower_bound(a)),s2.insert(a);
    cout<<*s1.begin()<<endl;
    for(i=1;i<n-1;i++)
        scanf("%d",&a),s2.erase(s2.lower_bound(a));
    cout<<*s2.begin()<<endl;
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
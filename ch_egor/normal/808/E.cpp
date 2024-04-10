#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 1 * 100 * 1000 + 228;
const int MAX_M = 3 * 100 * 1000 + 228;
int MAGIC = 528;

#define x first
#define y second

bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
	return a.y * b.x > b.y * a.x || (a.y * b.x == b.y * a.x && a.x > b.x);
}

int n, m;
ll dp[MAX_M];
pair<ll, ll> arr[MAX_N];

int maln()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld%lld", &arr[i].x, &arr[i].y);
	}

	sort(arr, arr + n, cmp);
	
	int ptr = 0;
	ll ans = 0;
	MAGIC = 100 * 1000 * 1000 / n;
	int fuck = 5 * 1500 * 1000 * 100;
	
	while (ptr < n && (ll)(n - ptr) * m > fuck)
	{
		m -= arr[ptr].x;
		ans += arr[ptr].y;
		++ptr;
	}
	
	memset(dp, 0, sizeof(dp));
	pair<ll, ll> *f = &arr[ptr];
	ll *now;
	for (int i = ptr; i < n; ++i)
	{
		now = dp + m;
		for (int j = m; j - f->x >= 0; --j)
		{
			*now = *now < *(now - f->x) + f->y ? *(now - f->x) + f->y : *now;
			--now;
		}
		++f;
	}

	printf("%lld\n", *max_element(dp, dp + m + 1) + ans);

	return 0;
}

priority_queue<int>Q[4] ;
priority_queue<int>P[4] ;
int  w , c ;
ll ans , dpp[4][300300];

ll f(int mid,int tot){
if( 2*mid > tot )return -(1<<30);
return dpp[2][mid]+dpp[1][ tot-2*mid ];
}

int main(){

scanf("%d %d",&n,&m);
while( n-- ){
    scanf("%d %d",&w,&c);
    Q[w].push(c);
}

for(int i=1;i<=m;i++){
ll x ;
if( Q[1].empty() )x=0;
else { x=1ll*Q[1].top();Q[1].pop(); }
dpp[1][i]=dpp[1][i-1]+x;
}

for(int i=1;i+i<=m;i++){
ll x ;
if( Q[2].empty() )x=0;
else { x=1ll*Q[2].top();Q[2].pop(); }
dpp[2][i]=dpp[2][i-1]+x;
}

for(int i=1;i+i+i<=m;i++){
ll x ;
if( Q[3].empty() )x=0;
else { x=1ll*Q[3].top();Q[3].pop(); }
dpp[3][i]=dpp[3][i-1]+x;
}


for(int i=0;3*i<=m;i++){

    ll tmp = dpp[3][i];
    int xm = m-3*i;

    int low=0,high = xm/2;
    while( low <high ){
        int mid = low+high>>1;

        if( f(mid,xm) >= f(mid+1,xm) ){
            high=mid;
        }else{
            low=mid+1;
        }

    }

   if( high )
        if( f(high,xm)<f(high-1,xm) )high--;

   if( high < xm/2 )
        if( f(high,xm)<f(high+1,xm) )high++;


   tmp+=dpp[2][high];
   xm-=2*high;
   tmp+=dpp[1][xm];

   ans=max( ans , tmp );
}

printf("%lld\n",ans);

return 0;
}
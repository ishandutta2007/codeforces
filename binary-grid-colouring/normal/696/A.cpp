#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
#include<set>
#include<stack>
#include <utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)
#define pii pair<int,int>
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson x << 1, l, mid  
#define rson x << 1 | 1, mid + 1, r  
const int lowbit(int x) { return x&-x; }  
const double eps = 1e-8;  
const int INF = 1e9+7; 
const ll inf =(1LL<<62) ;
const int MOD = 1e9 + 7;  
const ll mod = (1LL<<32);
const int N = 2e5+10; 
const int M=100010; 
template <class T1, class T2>inline void getmax(T1 &a, T2 b) {if (b>a)a = b;}  
template <class T1, class T2>inline void getmin(T1 &a, T2 b) {if (b<a)a = b;}
int read()
{
	int v = 0, f = 1;
	char c =getchar();
	while( c < 48 || 57 < c ){
		if(c=='-') f = -1;
		c = getchar();
	}
	while(48 <= c && c <= 57) 
		v = v*10+c-48, c = getchar();
	return v*f;
}
/*
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
*/

int n,m;
map<ll,ll>p;
ll a[4],fa,fb,ans;
int main()
{
    int i,j,k,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&a[0]);
        if(a[0]==1)
        {
            for(int i=1;i<=3;i++)scanf("%I64d",&a[i]);
            fa=a[1],fb=a[2];
            while(fa!=fb)
            {
                if(fa<fb) p[fb]+=a[3],fb>>=1;
                else p[fa]+=a[3], fa>>=1;
            }
        }
        else
        {
            for(int i=1;i<=2;i++) scanf("%I64d",&a[i]);
            ans=0LL;
            fa=a[1],fb=a[2];
            while(fa!=fb)
            {
                if(fa<fb)ans+=p[fb],fb>>=1;
                else ans+=p[fa],fa>>=1;
            }
            printf("%I64d\n",ans);
        }
    }
    return 0;
}
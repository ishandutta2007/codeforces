#pragma comment(linker, "/STACK:102400000,102400000")
//#include<bits/stdc++.h>
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
typedef pair<int,int> pii;
typedef vector<int> vi;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)
#define in freopen("in.txt","r",stdin) 
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson  l , mid , rt << 1  
#define rson  mid + 1 , r , rt << 1 | 1  
const int lowbit(int x) { return x&-x; }  
const double eps = 1e-8;  
const int INF = 1e9+7; 
const ll inf =(1LL<<62) ;
const int MOD = 1e9+7;  
const ll mod = (1LL<<32);
const int N =2e5+7; 
const int M=100010;
const ll MAX=1e18;
//const int maxn=1001; 
template <class T1, class T2>inline void getmax(T1 &a, T2 b) {if (b>a)a = b;}  
template <class T1, class T2>inline void getmin(T1 &a, T2 b) {if (b<a)a = b;}
int read(){
int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}

int Next[N];
int cntn=0,cntm=0;
struct Node{
    ll l;
    char c;
}S[N],t[N],s[N];

void build1(int n)
{
	for(int i=1;i<=n;++i)
	{
        scanf("%lld-%c",&t[cntn].l,&t[cntn].c);
        if(cntn && t[cntn].c==t[cntn-1].c)
		{
            t[cntn-1].l+=t[cntn].l;
        }
        else 
		{
            cntn++;
        }
    }
    return ;
}
void build2(int m)
{
	for(int i=1;i<=m;++i)
	{
        scanf("%lld-%c",&s[cntm].l,&s[cntm].c);
        if(cntm && s[cntm].c==s[cntm-1].c)
		{
            s[cntm-1].l+=s[cntm].l;
        }
        else 
		{
            cntm++;
        }
    }
    return ;
} 

void get_Next(int n)
{
    int i=0,j=-1;
	Next[i]=j;
    while(i<n-1)
	{
        if(j==-1||(s[i+1].c==s[j+1].c&&s[i+1].l==s[j+1].l))
		{
            i++;
			j++;
            Next[i]=j;
        }
        else j=Next[j];
    }
}
ll KMP(int n,int m)
{
    ll ans=0;
	int i=1,j=0;
    while(i<n-1)
	{
        if(j==-1||(t[i].c==s[j+1].c&&t[i].l==s[j+1].l))++i,++j;
        else 
		{
            j=Next[j];
        }
        if(j+1==m-1)
		{
            if(t[i-m+1].c==s[0].c&&t[i].c==s[m-1].c&&t[i-m+1].l>=s[0].l&&t[i].l>=s[m-1].l)
			ans++;
        }
    }
    return ans;
}

int main()
{
    int n,m;
    cin>>n>>m;
    
	build1(n);
	build2(m);
   
    ll ans=0;
    if(cntm==1)
	{
        for(int i=0;i<cntn;i++)
		{
            if(s[0].c==t[i].c&&s[0].l<=t[i].l)
			  ans+=t[i].l-s[0].l+1ll;
        }
    }
    else if(cntm==2)
	{
        for(int i=0;i<cntn;i++)
		{
            if(s[0].c==t[i].c&&s[1].c==t[i+1].c&&s[0].l<=t[i].l&&s[1].l<=t[i+1].l)
                ans++;
        }
    }
    else
	{
        get_Next(cntm);
        ans=KMP(cntn,cntm);
    }
    cout<<ans;
    return 0;
}
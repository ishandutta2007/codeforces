#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <bitset>
#include <iomanip>
#include <list>
#include <stack>
#include <utility> 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
const double eps = 1e-8;  
const int INF = 1e9+7; 
const ll inf =(1LL<<62) ;
const int MOD = 1e9 + 7;  
const ll mod = (1LL<<32);
const int N =1e6+6; 
const int M=100010;
const int maxn=1001;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)
#define pi acos(-1.0)
#define in freopen("in.txt","r",stdin) 
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson x << 1, l, mid  
#define rson x << 1 | 1, mid + 1, r  
const int lowbit(int x) { return x&-x; }
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
int main()
{
	ios::sync_with_stdio(false);
    string s,a,b;
    cin>>s>>a>>b;
    bool isok[2]={0,0};
    size_t idx=s.find(a);
    if(idx!=string::npos)
    {
        idx=s.find(b,idx+a.size());
        if(idx!=string::npos)isok[0]=1;
    }
  
    reverse(s.begin(),s.end());
    
    idx=s.find(a);
    if(idx!=string::npos)
    {
        idx=s.find(b,idx+a.size());
        if(idx!=string::npos)isok[1]=1;
    }
    
    if(isok[0] && isok[1])printf("both");
    else if(isok[0])printf("forward");
    else if(isok[1])printf("backward");
    else printf("fantasy");
	return 0;
}
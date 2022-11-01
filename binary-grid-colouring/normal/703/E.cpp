#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MP(x,y) make_pair(x,y)  
template <class T1, class T2>inline void getmax(T1 &a, T2 b) { if (b>a)a = b; }  
template <class T1, class T2>inline void getmin(T1 &a, T2 b) { if (b<a)a = b; }
int read()
{
	int v = 0, f = 0;
	char c =getchar();
	while( c < 48 || 57 < c ){
		if(c=='-') f = -1;
		c = getchar();
	}
	while(48 <= c && c <= 57) 
		v = v*10+c-48, c = getchar();
	return v*f;
}
const int N = 1010, M = 0, Z = 1e9 + 7, ms63 = 0x3f3f3f3f;  
int n, m; ll K;  
ll a[N];  
ll b[N];  
vector<ll>v;  
#include<unordered_map>  
unordered_map<ll, int>mop;  
pair<int, ll>f[N][N * 10];  
#define num first  
#define sum second  
void init()  
{  
    v.clear();  
    int top = sqrt(K + 0.5);  
    for (int i = 1; i <= top; ++i)if (K % i == 0)  
    {  
        v.push_back(i);  
        if (K / i != i)v.push_back(K / i);  
    }  
    sort(v.begin(), v.end());  
    m = v.size() - 1;  
    mop.clear(); for (int i = 0; i <= m; ++i)mop[v[i]] = i;  
    for (int i = 1; i <= n; ++i)  
    {  
        scanf("%I64d", &a[i]);  
        b[i] = __gcd(a[i], K);  
    }  
}  
  
void dp()  
{  
    if (K == 1)  
    {  
        puts("1");  
        printf("%I64d\n", min_element(a + 1, a + n + 1) - a);  
        return;  
    }  
    for (int j = 1; j <= m; ++j)f[0][j] = { n + 1, 0 };  
    for (int i = 1; i <= n; ++i)  
    {  
        for (int j = 0; j <= m; ++j)  
        {  
            f[i][j] = f[i - 1][j];  
            int pre = mop[v[j] / __gcd(v[j], b[i])];  
            getmin(f[i][j], MP(f[i - 1][pre].num + 1, f[i - 1][pre].sum + a[i]));  
        }  
    }  
    if (f[n][m].num > n)puts("-1");  
    else  
    {  
        printf("%d\n", f[n][m].num);  
        for (int i = n; i; --i)  
        {  
            if (f[i][mop[K]] != f[i - 1][mop[K]])  
            {  
                printf("%d ", i);  
                K /= __gcd(K, b[i]);  
            }  
        }  
        puts("");  
    }  
}  
int main()  
{  
    while (~scanf("%d%I64d", &n, &K))  
    {  
        init();  
        dp();  
    }  
    return 0;  
}
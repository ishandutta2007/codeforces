#pragma comment(linker, "/STACK:102400000,102400000")
//#include<bits/stdc++.h>
#include <stdio.h>
#include <string.h>
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
const int maxn=55555;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)
#define in freopen("in.txt","r",stdin) 
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson  l , mid , rt << 1    
#define rson  mid + 1 , r , rt << 1 | 1  
const int lowbit(int x) { return x&-x; }
//const int lowbit(int x) { return ((x)&((x)^((x)-1))); } 
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}

string s;
void solve1()
{
    int R=0,C=0;
    int flag = 0;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]=='C')flag=1;
        if(s[i]=='C')continue;
        if(flag==0)R=R*10+(s[i]-'0');
        else C=C*10+(s[i]-'0');
    }
    string ans;
    while(C)
    {
        int p = (C-1)%26;
        C=(C-1)/26;
        ans+=(p+'A');
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<R<<endl;
}
void solve2()
{
    int flag = 0;
    int C=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]<='9'&&s[i]>='0'&&flag==0)
        {
            flag = 1;
            cout<<"R";
        }
        if(flag==1)cout<<s[i];
        else
            C=C*26+(s[i]-'A'+1);
    }
    cout<<"C"<<C<<endl;
}
int main()
{
    int time;
    scanf("%d",&time);
    while(time--)
    {
        cin>>s;
        int flag1=0,flag2=0,flag3=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='R')flag1++;
            if(s[i]=='C')flag2++;
            if(s[i]<='Z'&&s[i]>='A')
                flag3++;
        }
        if(s[0]=='R'&&s[1]=='C')flag1=0;
        if(flag3==2&&flag1&&flag2)
            solve1();
        else
            solve2();
    }
}
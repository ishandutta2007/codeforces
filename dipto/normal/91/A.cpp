#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
#define INF 2000000000
#define FOR(i,x,n) for(int i=x;i<=n;i++)
#define REV(i,x,n) for(int i=x;i>=n;i--)
#define si(x) scanf("%d",&x)
#define ss(x) scanf("%s",x)
#define sl(x) scanf("%lld",&x)
#define sd(x) scanf("%lf",&x)
#define LL long long
#define test int T;scanf("%d",&T);while(T--)
#define pb push_back
#define pob() pop_back()
#define b() begin()
#define e() end()
#define s() size()
#define cl() clear()
#define mp make_pair
#define fi first
#define se second
#define LD long double
#define SZ 1000005
/**************************************************************************************/
char s1[SZ],s2[SZ];
vector<int> ind[26];

int main()
{
ss(s1);ss(s2);
int l1=strlen(s1),l2=strlen(s2);
FOR(i,0,l1-1)
ind[s1[i]-'a'].pb(i);
FOR(i,0,25) sort(ind[i].b(),ind[i].e());

int pos=INF,cnt=0;
FOR(i,0,l2-1)
{
char ch=s2[i];
if(ind[ch-'a'].empty()) {cnt=-1;break;}
if(pos>=ind[ch-'a'].back()) {cnt++;pos=ind[ch-'a'][0];continue;}
pos=*upper_bound(ind[ch-'a'].b(),ind[ch-'a'].e(),pos);}

printf("%d\n",cnt);
return 0;
}
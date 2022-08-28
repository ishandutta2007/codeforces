#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
using namespace std;
int n,m,i,j,tt;
map<char,int> mp;
string s,t,p;
int main()
{
	scanf("%d",&tt);
	while(tt--){
		rdst(s,105);
		rdst(t,105);
		rdst(p,105);
		mp.clear();
		fz0k(i,s.length())mp[s[i]]++;
		fz0k(i,t.length())mp[t[i]]--;
		fz0k(i,p.length())mp[p[i]]++;
		bool f=1;
		ff(mp,it){
			if(it->second<0)f=0;
		}
		if(!f){
			puts("NO");
			continue; 
		}
		j=0;
		fz0k(i,t.length()){
			if(j<s.length()&&s[j]==t[i])j++;
		}
		if(j==s.length()){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}
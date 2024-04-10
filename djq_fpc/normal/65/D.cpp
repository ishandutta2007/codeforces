#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<queue>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);++(i))
#define fd1(i,n) for ((i)=(n);(i)>=1;--(i))
#define fz0g(i,n) for ((i)=0;(i)<=(n);++(i))
#define fd0g(i,n) for ((i)=(n);(i)>=0;--(i))
#define fz0k(i,n) for ((i)=0;(i)<(n);++(i))
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;--(i))
#define fz(i,x,y) for ((i)=(x);(i)<=(y);++(i))
#define fd(i,y,x) for ((i)=(y);(i)>=(x);--(i))
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
using namespace std;
struct ii
{
	int g,h,r,s;
};
bool operator <(const ii&x,const ii&y)
{
	if(x.g!=y.g) return x.g<y.g;
	if(x.h!=y.h) return x.h<y.h;
	if(x.r!=y.r) return x.r<y.r;
	return x.s<y.s;
}
set<ii> dp[10005];
set<string> ans;
int n,m,i,j;
string st;
int main()
{
	scanf("%d",&n);
	rdst(st,10005);
	st=" "+st;
	dp[0].insert((ii){0,0,0,0});
	fz1(i,n){
		ff(dp[i-1],it){
			ii t=*it;
			if(st[i]!='?'){
				if(st[i]=='G') t.g++;
				if(st[i]=='H') t.h++;
				if(st[i]=='R') t.r++;
				if(st[i]=='S') t.s++;
				dp[i].insert(t);
			}
			else{
				int mi=min(min(t.g,t.h),min(t.r,t.s));
				if(t.g==mi){
					t.g++;
					dp[i].insert(t);
					t.g--;
				}
				if(t.h==mi){
					t.h++;
					dp[i].insert(t);
					t.h--;
				}
				if(t.r==mi){
					t.r++;
					dp[i].insert(t);
					t.r--;
				}
				if(t.s==mi){
					t.s++;
					dp[i].insert(t);
					t.s--;
				}
			}
		}
	}
	ff(dp[n],it){
		ii t=*it;
		int mi=min(min(t.g,t.h),min(t.r,t.s));
		if(t.g==mi){
			ans.insert("Gryffindor");
		}
		if(t.h==mi){
			ans.insert("Hufflepuff");
		}
		if(t.r==mi){
			ans.insert("Ravenclaw");
		}
		if(t.s==mi){
			ans.insert("Slytherin");
		}
	}
	ff(ans,it){
		cout<<*it<<endl;
	}
	return 0;
}
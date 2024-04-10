#include<cstdio>
#include<cstring>
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
using namespace std;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
void putint(LL n)
{
     char a[20];
     int size=0;
     if (n==0)
        putchar('0');
     while (n)
     {
           a[size++]=n%10+48;
           n/=10;
     }
     for (int i=size-1;i>=0;i--)
         putchar(a[i]);
     putchar('\n');
}
int n,a[100010],b[100010],l,r;
LL s,ans[100010];
set<pair<pair<int,int>,LL> > S;
multiset<LL> SS;
int main()
{
	scanf("%d",&n);
	FOR(i,1,n) getint(a[i]);
	FOR(i,1,n) getint(b[i]);
	ans[n]=0;
	FORD(i,n-1,1){
		s=a[b[i+1]];
		r=b[i+1];
		l=b[i+1];
		set<pair<pair<int,int>,LL> >::iterator it=S.lower_bound(mp(mp(b[i+1]+1,0),0));
		if (it!=S.end()){
			pair<pair<int,int>,LL> A=*it;
			if (A.fi.fi==b[i+1]+1){
				S.erase(it);
				s+=A.se;
				SS.erase(SS.find(A.se));
				r=max(r,A.fi.se);
			}
		}
		it=S.lower_bound(mp(mp(b[i+1]+1,0),0));
		
		if (it!=S.begin()){
			it--;
			pair<pair<int,int>,LL> A=*it;
			if (A.fi.se==b[i+1]-1){
				S.erase(it);
				s+=A.se;
				SS.erase(SS.find(A.se));
				l=min(l,A.fi.fi);
			}
		}
		S.insert(mp(mp(l,r),s));
		SS.insert(s);
		multiset<LL>::iterator it1=SS.end();
		it1--;
		ans[i]=*it1;
	}
	FOR(i,1,n) cout<<ans[i]<<endl;
	return 0;
}
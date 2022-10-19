#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
struct team{
	str name;
	int pnt,w,l;
}t[55];
int n;
void update(str s,int win,int lose)
{
	rep(i,n) if(t[i].name==s)
	{
		if(win>lose) t[i].pnt+=3;
		elif(win==lose) t[i].pnt++;
		t[i].w+=win;
		t[i].l+=lose;
		break;
	}
}
bool cmp(team a,team b)
{
	if(a.pnt!=b.pnt) return a.pnt>b.pnt;
	if(a.w-a.l!=b.w-b.l) return (a.w-a.l)>(b.w-b.l);
	if(a.w!=b.w) return a.w>b.w;
	return 0;
}
bool cmp2(team a,team b)
{
	return a.name<b.name;
}
int main()
{
	cin>>n;
	rep(i,n) cin>>t[i].name;
	rep(i,n*(n-1)/2)
	{
		cin.ignore();
		str nam1,nam2;
		int num1,num2;
		getline(cin,nam1,'-');getline(cin,nam2,' ');
		scanf("%d:%d",&num1,&num2);
		update(nam1,num1,num2);update(nam2,num2,num1);
	}
	sort(t,t+n,cmp);
	sort(t,t+n/2,cmp2);
	rep(i,n/2) cout<<t[i].name<<endl;
	return 0;
}
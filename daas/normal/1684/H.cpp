#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int MAXN=1e6+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,val[MAXN],pre[MAXN];
char s[MAXN];
vector<pair<int,int> > ANS;
void ins(int l,int r) {ANS.push_back(make_pair(l,r));}
void calc58(int l,int r)
{
	for(int i=l;i<r;++i) if(val[i] && !val[i+1])
	{
		for(int j=l;j<i;++j) ins(j,j);
		ins(i,i+2);
		for(int j=i+3;j<=r;++j) ins(j,j);
		break;
	}
}
void solve(int L,int R,int num,int goal)
{
	if(L>R) puts("asdasdasda"),exit(0);
	if(num==goal)
	{
		for(int i=L;i<=R;++i) ins(i,i);
		return;
	}
	if(num==3)
	{
		int st=L; while(!val[st]) ++st;
		int ed=R; while(!val[ed]) --ed;
		if(ed-st+1==3)
		{
			for(int i=L;i<st;++i) ins(i,i);
			ins(st,st+1);
			ins(ed,ed);
			for(int i=ed+1;i<=R;++i) ins(i,i);
		}
		else
		{
			int flag=0;
			for(int i=L;i<=R;++i) if(val[i])
			{
				if(flag) ins(i,i);
				else if(!val[i+1]) ins(i,i+1),++i,flag=1;
				else ins(i,i);
			}
			else ins(i,i);
		}
		return;
	}
	if(num==4 && goal==8)
	{
		int st=L; while(!val[st]) ++st;
		for(int i=L;i<st;++i) ins(i,i);
		ins(st,st+2);
		if(val[st+1]==1)
		{
			for(int i=st+3;i<=R;++i) ins(i,i);
			return;
		}
		if(val[st+1]==0 && val[st+2]==0)
		{
			solve(st+3,R,3,4);
			return;
		}
		if(val[st+1]==0 && val[st+2]==1)
		{
			int st2=st+3; while(!val[st2]) ++st2;
			for(int i=st+3;i<st2;++i) ins(i,i);
			ins(st2,st2+1);
			for(int i=st2+2;i<=R;++i) ins(i,i);
			return;
		}
	}
	if(num==9 && goal==16)
	{
		int st=L; while(!val[st]) ++st;
		for(int i=L;i<st;++i) ins(i,i);
		ins(st,st+2);
		if(val[st+1]==0 && val[st+2]==0)
		{
			int mn=4,l=st+3,r=R,div;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(pre[mid]-pre[st+2]<=mn) div=mid,l=mid+1;
				else r=mid-1;
			}
			solve(st+3,div,4,4);
			solve(div+1,R,4,8);
			return;
		}
		if(val[st+1]==0 && val[st+2]==1)
		{
			int mn=4,l=st+3,r=R,div;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(pre[mid]-pre[st+2]<=mn) div=mid,l=mid+1;
				else r=mid-1;
			}
			solve(st+3,div,4,8);
			for(int i=div+1;i<=R;++i) ins(i,i);
			return;
		}
		if(val[st+1]==1 && val[st+2]==0)
		{
			st+=3;
			while(!val[st])
			{
				ins(st,st);
				++st;
			}
			ins(st,st);
			++st;
		}
		else st+=3;
		int S=st,T=R;
		while(!val[S]) ++S;
		while(!val[T]) --T;
		for(int i=st;i<S;++i) ins(i,i);
		if(T-S+1==6)
		{
			ins(S,S+1);
			ins(S+2,S+3);
			ins(S+4,S+5);
		}
		else
		{
			if(val[S+1]==1)
			{
				ins(S,S);
				calc58(S+1,T);
			}
			else
			{
				calc58(S,T-1);
				ins(T,T);
			}
		}
		for(int i=T+1;i<=R;++i) ins(i,i);
		return;
	}
	int mn=num/2,l=L,r=R,div;
	if((num==10 && goal==16) || (num==11 && goal==16)) mn=4;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(pre[mid]-pre[L-1]<=mn) div=mid,l=mid+1;
		else r=mid-1;
	}
	solve(L,div,mn,goal/2);
	solve(div+1,R,num-mn,goal/2);
}
void spe_solve()
{
	int st=1; while(!val[st]) ++st;
	int ed=n; while(!val[ed]) --ed;
	for(int i=1;i<st;++i) ins(i,i);
	if(ed-st+1==5)
	{
		ins(st,st+3);
		ins(ed,ed);
	}
	else calc58(st,ed);
	for(int i=ed+1;i<=n;++i) ins(i,i);
}
int main()
{
	T=read();
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=1;i<=n;++i) val[i]=s[i]-'0',pre[i]=pre[i-1]+val[i];
		if(!pre[n]) {puts("-1");continue;}
		int ans=1; while(ans<pre[n]) ans<<=1;
		ANS.clear();
		if(pre[n]==5) spe_solve();
		else solve(1,n,pre[n],ans);
		printf("%d\n",(int)ANS.size());
		for(int i=0;i<(int)ANS.size();++i) printf("%d %d\n",ANS[i].first,ANS[i].second);
	}
	return 0;
}
//ore no turn,draw!
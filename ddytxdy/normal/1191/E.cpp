#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50,inf=1e9;
int n,k,mi[2],ma[2];char c[N];bool flag;
set<int>s[2];
set<int>::iterator it,jt;
void win(){
	puts("tokitsukaze");exit(0);
}
void fail(){
	puts("quailty");exit(0);
}
void ping(){
	puts("once again");
}
int main(){
	scanf("%d%d%s",&n,&k,c+1);
	s[0].insert(-inf);s[0].insert(inf);s[1].insert(-inf);s[1].insert(inf);
	for(int i=1;i<=n;i++){
		int dat=c[i]-'0';
		s[dat].insert(i);
		if(!mi[dat])mi[dat]=i;
		ma[dat]=i;
	}//cout<<1;
	if(ma[0]-mi[0]+1<=k||ma[1]-mi[1]+1<=k)win();
	for(int i=1;i<=n-k+1;i++){
		int r=i+k-1;bool flagg=0,flaggg=0;
		it=s[0].lower_bound(i);it--;
		jt=s[0].lower_bound(r+1);
		if(*it==-inf&&ma[0]-*jt+1<=k)flagg=1;
		if(*jt==inf&&*it-mi[0]+1<=k)flagg=1;
		it=s[1].lower_bound(i);it--;
		jt=s[1].lower_bound(r+1);
		if(*it==-inf&&ma[1]-*jt+1<=k)flaggg=1;
		if(*jt==inf&&*it-mi[1]+1<=k)flaggg=1;
		if(!flagg||!flaggg)flag=1;
	}
	if(!flag)fail();
	ping();
	return 0;
}
//5 2
//01101
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,m,k,s1[N],s2[N],n1,n2;
set<int>ss1[N],ss2[N];
bool check(int x1,int y1,int x2,int y2,int op){
	if(x1>x2||y1>y2)return 1;
	if(op==0){
		int y=*ss1[x1].lower_bound(y1);
		for(int i=y;i<=y2;i++)if(s2[i]+n1!=n)return 0;
		n1++;return check(x1+1,y1,x2,min(y2,y-1),1);
	}
	if(op==1){
		int x=*ss2[y2].lower_bound(x1);
		for(int i=x;i<=x2;i++)if(s1[i]+n2!=m)return 0;
		n2++;return check(x1,y1,min(x2,x-1),y2-1,2);
	}
	if(op==2){
		int y=*(--ss1[x2].upper_bound(y2));
		for(int i=y1;i<=y;i++)if(s2[i]+n1!=n)return 0;
		n1++;return check(x1,max(y1,y+1),x2-1,y2,3);
	}
	if(op==3){
		int x=*(--ss2[y1].upper_bound(x2));
		for(int i=x1;i<=x;i++)if(s1[i]+n2!=m)return 0;
		n2++;return check(max(x1,x+1),y1+1,x2,y2,0);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)ss1[i].insert(0),ss1[i].insert(m+1);
	for(int i=1;i<=m;i++)ss2[i].insert(0),ss2[i].insert(n+1);
	for(int i=1,x,y;i<=k;i++)scanf("%d%d",&x,&y),s1[x]++,s2[y]++,ss1[x].insert(y),ss2[y].insert(x);
	puts(check(1,1,n,m,0)?"Yes":"No");
	return 0;
}
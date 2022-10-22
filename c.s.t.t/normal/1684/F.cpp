/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int T,n,m,lp[200100],rp[200100],a[200100],b[200100],pos[200100],res;
vector<int>u[200100];
void mina(){
	scanf("%d%d",&n,&m),res=0x3f3f3f3f;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
	for(int i=0;i<=n+1;i++)lp[i]=n+1,rp[i]=0;
	for(int i=1,l,r;i<=m;i++)scanf("%d%d",&l,&r),rp[l]=max(rp[l],r),lp[r]=min(lp[r],l);
	for(int i=1;i<=n;i++)rp[i]=max(rp[i],rp[i-1]);
	for(int i=n;i>=1;i--)lp[i]=min(lp[i],lp[i+1]);
	sort(b+1,b+n+1),m=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+m+1,a[i])-b,pos[i]=u[a[i]].size(),u[a[i]].push_back(i);
	int l=1,r=n;
	while(l<=r){
		if(pos[l]&&u[a[l]][pos[l]-1]>=lp[l])break;
		l++;
	}
	res=min(res,r-l+1);
	for(;r>1;){
		if(pos[r]+1!=u[a[r]].size()&&u[a[r]][pos[r]+1]<=rp[r])break;
		if(!pos[r]||lp[r]==n+1){r--,l=min(l,r+1),res=min(res,r-l+1);continue;}
		int pos=*lower_bound(u[a[r]].begin(),u[a[r]].end(),lp[r]);
		l=min(l,pos);
		r--,l=min(l,r+1),res=min(res,r-l+1);
	}
	printf("%d\n",res);
	for(int i=1;i<=m;i++)u[i].clear();
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}
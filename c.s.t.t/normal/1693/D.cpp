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
int n,a[200100],lp[200100],hf[200100],lf[200100],stk[200100],tp;
int ha[200100][20],la[200100][20];
int pos[200100];
int num(int anc[200100][20],int s,int t){
	int r=0;
	for(int i=19;i>=0;i--)if(anc[s][i]&&anc[s][i]>=t)r+=1<<i,s=anc[s][i];
	return r;
}
void build(){
	memset(hf,0,sizeof(hf)),memset(lf,0,sizeof(lf));
	memset(ha,0,sizeof(ha)),memset(la,0,sizeof(la));
	for(int i=1;i<=n;i++){
		while(tp&&a[stk[tp]]<a[i])tp--;
		hf[i]=stk[tp],stk[++tp]=i;
	}tp=0;
	for(int i=1;i<=n;i++){
		while(tp&&a[stk[tp]]>a[i])tp--;
		lf[i]=stk[tp],stk[++tp]=i;
	}tp=0;
	for(int i=1;i<=n;i++){
		ha[i][0]=hf[i],la[i][0]=lf[i];
		for(int j=1;j<20;j++)ha[i][j]=ha[ha[i][j-1]][j-1],la[i][j]=la[la[i][j-1]][j-1];
	}
	for(int i=1,l,r;i<=n;i++){
		l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			int qwq=num(ha,i,mid)+num(la,i,mid)+1;
			// printf("|%d,%d|:%d\n",mid,i,qwq);
			if(qwq==i-mid+1)r=mid;else l=mid+1;
		}
		pos[i]=l;
	}
}
int phf[200100],plf[200100],shf[200100],slf[200100];
int pre[200100],suf[200100];
long long res;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build();
	for(int i=1;i<=n;i++)phf[i]=hf[i],plf[i]=lf[i],pre[i]=pos[i];
	reverse(a+1,a+n+1);
	build();
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++)shf[n-i+1]=n-hf[i]+1,slf[n-i+1]=n-lf[i]+1,suf[n-i+1]=n-pos[i]+1;
	// for(int i=1;i<=n;i++)printf("[%d,%d,%d]",pre[i],phf[i],plf[i]);puts("");
	// for(int i=1;i<=n;i++)printf("[%d,%d,%d]",suf[i],shf[i],slf[i]);puts("");
	for(int i=1;i<=n;i++)lp[i]=pre[i];
	for(int i=1;i<=n;i++)lp[suf[i]]=min(lp[suf[i]],i);
	for(int i=1;i<n;i++){
		for(int A=0;A<2;A++)for(int B=0;B<2;B++){
			int pi,pd,pp;
			if(A==0){
				pi=a[i];
				if(B==0){
					if(phf[i]<pre[i])continue;
					pp=pre[i],pd=a[phf[i]];
				}else pp=max(pre[i],phf[i]+1),pd=n+1;
			}else{
				pd=a[i];
				if(B==0){
					if(plf[i]<pre[i])continue;
					pp=pre[i],pi=a[plf[i]];
				}else pp=max(pre[i],plf[i]+1),pi=0;
			}
			for(int C=0;C<2;C++)for(int D=0;D<2;D++){
				int si,sd,ss;
				if(C==0){
					si=a[i+1];
					if(D==0){
						if(shf[i+1]>suf[i+1])continue;
						ss=suf[i+1],sd=a[shf[i+1]];
					}else ss=min(suf[i+1],shf[i+1]-1),sd=n+1;
				}else{
					sd=a[i+1];
					if(D==0){
						if(slf[i+1]>suf[i+1])continue;
						ss=suf[i+1],si=a[slf[i+1]];
					}else ss=min(suf[i+1],slf[i+1]-1),si=0;
				}
				// printf("%d|%d,%d,%d,%d|%d,%d,%d,%d|%d,%d\n",i,A,B,C,D,pi,pd,si,sd,pp,ss);
				if(pd>si&&pi<sd)lp[ss]=min(lp[ss],pp)/*,printf("%d:(%d,%d)\n",i,pp,ss)*/;
			}
		}
	}
	for(int i=n-1;i;i--)lp[i]=min(lp[i],lp[i+1]);
	for(int i=1;i<=n;i++)res+=i-lp[i]+1;
	printf("%lld\n",res);
	return 0;
}
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
const int inf=0x3f3f3f3f,MX=1000111,MXN=1011;
int n,k;
int a[MX],ps[MXN],ng[MXN],pst[MXN],ngt[MXN],psc,ngc;
int fp[MX],fn[MX],qp[MX],qn[MX];
int wk(){
	int ans=inf;
	memset(fp,inf,sizeof(fp));fp[0]=0;
	memset(fn,inf,sizeof(fn));fn[0]=0;
	int ph=0,pt=0,nh=0,nt=0;
	qp[++pt]=0,qn[++nt]=0;
	while(ph<pt||nh<nt){
		if(qp[ph+1]<=qn[nh+1]){
			int r=qp[++ph];
			if(r)ans=min(ans,fp[r]+fn[r]);
			if(fp[r]+1>=ans)continue;
			for(int i=1;i<=psc;i++)if(fp[r+pst[i]]==inf){
				fp[qp[++pt]=r+pst[i]]=fp[r]+1;
			}
		}else{
			int r=qn[++nh];
			if(r)ans=min(ans,fp[r]+fn[r]);
			if(fn[r]+1>=ans)continue;
			for(int i=1;i<=ngc;i++)if(fn[r+ngt[i]]==inf){
				fn[qn[++nt]=r+ngt[i]]=fn[r]+1;
			}
		}
	}
	return ans;
}
inline int gcd(int a,int b){
	if(a<b)swap(a,b);while(b)b^=a^=b^=a%=b;return a;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)scanf("%d",&a[i]);
	for(int i=1;i<=k;i++)a[i]-=n;
	for(int i=1;i<=k;i++){
		if(a[i]==0){
			printf("1\n");return 0;
		}else if(a[i]>0)ps[a[i]]=1;
		else ng[-a[i]]=1;
	}
	for(int i=1;i<=1000;i++)if(ps[i])pst[++psc]=i;
	for(int i=1;i<=1000;i++)if(ng[i])ngt[++ngc]=i;
	if(!psc||!ngc){
		printf("-1\n");return 0;
	}
	printf("%d\n",wk());
	return 0;
}
#include<cstdio>
#include<map>
typedef long long ll;
const int N=1e5+3;
int n,m,a,b,c,alpha,pp,p[N],np[N],k,d[N];long long ans;
std::map<int,int>t;
signed main(){
	for(int i=2;i<N;i++){
	  if(!np[i])p[++k]=i,d[i]=i;
	  for(int j=1;j<=k&&i*p[j]<N;j++){
		np[i*p[j]]=1;
		if(i%p[j])d[i*p[j]]=p[j];
		else {d[i*p[j]]=d[i];break;}
	  }
	}
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
	  scanf("%d",&a);if(m>33&&a>1)continue;
	  b=c=1;
	  for(;a>1;){
		pp=d[a];alpha=0;
		for(;a%pp==0;a/=pp)alpha++;
		alpha%=m;
		if(alpha)for(int j=0;j<alpha;j++)b*=pp;
		if(alpha&&~c)for(int j=0;j<m-alpha;j++){
		  if((ll)c*pp>N){c=-1;break;}
		  c*=pp;
		}
	  }
	  ans+=t[c];
	  t[b]++;
	}printf("%lld",ans);
	return 0;
}
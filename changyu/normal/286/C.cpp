#include<cstdio>
#include<vector>
#include<algorithm>
const int N=1e6+3;
int n,a[N],tmp[N],k,f[N],t,b[N];
std::vector<int>p[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),tmp[i]=a[i];
	std::sort(tmp+1,tmp+1+n);
	for(int i=1;i<=n;i++)
	  if(tmp[i]!=tmp[i-1])tmp[++k]=tmp[i];
	for(int i=1;i<=n;i++)
	  a[i]=std::lower_bound(tmp+1,tmp+1+k,a[i])-tmp;
	scanf("%d",&t);
	for(int i;t--;)scanf("%d",&i),f[i]=1;
	for(int i=n;i;i--){
	  if(f[i]||!p[a[i]].size()||b[i+1]-b[p[a[i]][p[a[i]].size()-1]]){
		b[i]=b[i+1]+1;
		p[a[i]].push_back(i);
	  }
	  else{
		b[i]=b[i+1]-1;
		p[a[i]].pop_back();
	  }
	}
	if(b[1])return 0*puts("NO");
	puts("YES");
	for(int i=1;i<=n;i++)printf("%d ",(b[i+1]-b[i])*tmp[a[i]]);
	return 0;
}
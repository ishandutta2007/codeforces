#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;
template<class T>
void read(T &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
int id[N],a[N],p[N][2];
int sigma[N],f[N],b[N],c[N];
int sum[N];
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
void merge(int x,int y){
	int f1=find(x),f2=find(y);
	if(f1!=f2)f[max(f1,f2)]=min(f1,f2);
}
//void output(int n){
//	int i;
//	for(i=1;i<=n;++i)printf("%d ",sigma[i]);
//	puts("");
//}
int main(){
	int T,n,i,x,tot,s,cnt;
	read(T);
	while(T--){
		read(n);
		tot=cnt=0;
		for(i=1;i<=n;++i){
			f[i]=i;
			id[i]=a[i]=0;
			sum[i]=0;
			p[i][0]=p[i][1]=0;
		}
		for(i=1;i<=n;++i){
			read(x);
			c[i]=b[i]=x;
			++sum[x];
			if(id[x]==0){
				id[x]=i;
				++tot;
				a[i]=tot;
				p[a[i]][0]=i;
			}
			else{
				a[i]=a[id[x]];
				p[a[i]][1]=i;
				id[x]=0;
			}
		}
		s=0;
		sort(c+1,c+1+n);
		for(i=1;i<=n;++i){
			if(c[i]==c[i-1])continue;
			s+=(sum[c[i]]&1);
		}
		if(s>=2||(s==1&&sum[b[(n+1)/2]]==1)){
			puts("NO");
			continue;
		}
		puts("YES");
		for(i=1;i<=tot;++i){
			if(p[i][1]){
				sigma[++cnt]=p[i][0];
				sigma[n-cnt+1]=p[i][1];
			}
			else{
				sigma[(n+1)/2]=p[i][0];
			}
		}
		//output(n);
		if((n&1) && (sigma[(n+1)/2]*2==n+1)){
			for(i=1;i<=n;++i){
				if(b[sigma[i]]==b[sigma[(n+1)/2]] && i*2!=(n+1)){
					swap(sigma[i],sigma[(n+1)/2]);
					break;
				}
			}
		}
		for(i=1;i<=n;++i){
			merge(i,sigma[i]);
		}
		for(i=1;i<=n;++i){
			if(find(i)!=find(n+1-i)){
				swap(sigma[i],sigma[n+1-i]);
				merge(i,n+1-i);
			}
		}
		for(i=1;i<=n;++i){
			if(find(i)==find(1))continue;
			int x=sigma[i],y=sigma[1],z=sigma[n+1-i],t=sigma[n];
			sigma[1]=x;
			sigma[n+1-i]=y;
			sigma[n]=z;
			sigma[i]=t;
			merge(1,i);
		}
		for(i=1;i<=n;++i)printf("%d ",sigma[i]);
		puts("");
	}
	return 0;
}
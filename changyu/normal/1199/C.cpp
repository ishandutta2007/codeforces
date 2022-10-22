#include<cstdio>
#include<algorithm>
#include<map>
const int N=4e5+1;
int n,m,t,a[N],c,ans;std::map<int,int>f;
int main(){
	scanf("%d%d",&n,&t);
	m=1;
	for(int i=1;i<=8*t/n;i++){
	  m<<=1;
	  if(m>=n){m=n;break;}
	}
	//m=Pow(2,8*m/n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	std::sort(a+1,a+1+n);
	for(int i=1,j=1;i<=n;i++){
		if(!f[a[i]])c++;
		f[a[i]]++;
		for(;c>m;j++){
		  f[a[j]]--;
		  if(!f[a[j]])c--;
		}if(i-j+1>ans)ans=i-j+1;
	}printf("%d",n-ans);
	return 0;
}
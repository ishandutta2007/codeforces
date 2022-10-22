#include<cstdio>
const int N=2e5+3;
int n,m,b[26],ans;char a[N];
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d%d",&n,&m);
	scanf("%s",a+1);
	ans=0;
	for(int i=1,mx;i+i<=m;i++){
	  for(int i=0;i<26;i++)b[i]=0;
	  mx=0;
	  for(int j=i;j<=n;j+=m){
		b[a[j]-'a']++;
		if(b[a[j]-'a']>mx)mx=b[a[j]-'a'];//printf("%d\n",j);
	  }
	  for(int j=m-i+1;j<=n;j+=m){
		b[a[j]-'a']++;
		if(b[a[j]-'a']>mx)mx=b[a[j]-'a'];//printf(" %d\n",j);
	  }
	  ans+=n/m*2-mx;
	}
	if(m&1){
	  int mx;
	  for(int i=0;i<26;i++)b[i]=0;
	  mx=0;
	  for(int i=m/2+1;i<=n;i+=m){
		b[a[i]-'a']++;
		if(b[a[i]-'a']>mx)mx=b[a[i]-'a'];
	  }
	  ans+=n/m-mx;
	}
	printf("%d\n",ans);
	}return 0;
}
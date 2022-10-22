#include<cstdio>
const int N=2003;
int n,m;char a[N],b[N];
//need ()()((()))
inline void Reverse(int l,int r){
	for(int i=l;i<=r;i++)b[i]=a[i];
	for(int i=l;i<=r;i++)a[i]=b[l+r-i];
}
inline int Find(int i,char c){for(;a[i]!=c;i++);return i;}
int main(){
	int tmp;
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d%d%s",&n,&m,a+1);m--;
	printf("%d\n",n);
	for(int i=1;i<=n;i++){
	  if(i<=m+m&&(~i&1)||i>n-(n-m-m)/2){
	  	tmp=Find(i,')');
		Reverse(i,tmp);
		printf("%d %d\n",i,tmp);
	  }
	  else{
		tmp=Find(i,'(');
		Reverse(i,tmp);
		printf("%d %d\n",i,tmp);
	  }
	}//printf("%s\n",a+1);
	}return 0;
}
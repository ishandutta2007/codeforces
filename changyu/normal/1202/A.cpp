#include<cstdio>
#include<cstring>
const int N=1e5+9;
int l1,l2,a[N],b[N],lowbit;char t1[N],t2[N];
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%s%s",t1,t2);l1=strlen(t1),l2=strlen(t2);
	for(int i=0;i<l1;i++)a[i]=t1[l1-i-1]-48;
	for(int i=0;i<l2;i++)b[i]=t2[l2-i-1]-48;
	for(int i=0;i<l2;i++)if(b[i]){lowbit=i;break;}
	for(int i=0;i<l1;i++)if(a[i]&&i>=lowbit)
	  {printf("%d\n",i-lowbit);break;}
	}return 0;
}
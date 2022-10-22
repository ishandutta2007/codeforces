#include<cstdio>
#include<vector>
using namespace std;
int n,k[100002],f0[100002],f1[100002],s,b0[500002],b1[500002],b8,t,nt;char a[500002],tmp[500002];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
	  scanf("%s",tmp);
	  for(int j=0;tmp[j];j++)
		a[k[i-1]+j]=tmp[j],k[i]=k[i-1]+j+1;
	}
	for(int i=1;i<=n;i++){
	  t=0;nt=1e7;
	  for(int j=k[i-1];j<k[i];j++)
		t+=a[j]=='('?1:-1,nt=min(nt,t);
	  if(t>0&&nt>=0)b0[t]++;
	  if(f1[i]=nt==t&&nt<0)b1[-t]++;
	  if(nt==0&&t==0)b8++;
	}
	for(int i=1;i<500002;i++)
	  s+=min(b0[i],b1[i]);
	printf("%d",s+b8/2); 
	return 0; 
}
#include<cstdio>
int num[100005],ns[100005],lst[100005];
int main(){
	int n,in,prev,nsum=1,numl,len,max;
	scanf("%d",&n);
	scanf("%d",&numl);
	prev=numl;
	ns[0]=1;
	for(int k=1;k<n;k++){
	scanf("%d",&in);
		if(in==prev)
		ns[nsum-1]++;
		else{
			lst[nsum]=in-numl;
			numl=in;
			ns[nsum]=1;
			nsum++;
		}
		prev=in;
	}
	len=max=ns[0];
	for(int k=1;k<nsum;k++){
		if(lst[k]==lst[k-1])
		len=ns[k]+ns[k-1];
		else
		len+=ns[k];
		if(len>max)max=len;
	}
	printf("%d",max);
	return 0;
}
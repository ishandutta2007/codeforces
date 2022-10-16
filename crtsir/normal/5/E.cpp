#include<bits/stdc++.h>
using namespace std;
int l[1000003],r[1000003],n,cnt[1000003],a[1000003],b[1000003],p;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		if(a[i]>a[p])p=i;
	}
	for(int i=0;i<n;i++)
		b[i]=a[(i+p)%n];
	b[n]=a[p];
	for(int i=1;i<=n;i++){
		l[i]=i-1;
		while(l[i]&&b[i]>=b[l[i]])l[i]=l[l[i]];
	}
	for(int i=n-1;i>-1;i--){
		r[i]=i+1;
		while(r[i]<n&&b[i]>b[r[i]])r[i]=r[r[i]];
		if(r[i]<n&&b[i]==b[r[i]])
		{
			if(b[i]==b[r[i]])cnt[i]=cnt[r[i]]+1;
			r[i]=r[r[i]];
		}
	}
	long long ans=0;
	for(int i=0;i<n;i++){
		ans+=cnt[i];
		if(b[i]<b[0])ans+=2-((l[i]==0)&(r[i]==n));
	}
	cout<<ans;
}
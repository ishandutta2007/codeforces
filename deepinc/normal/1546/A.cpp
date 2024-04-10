#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
const int $=555555;
int n,a[111],b[111],q1[111],q2[111],h1,t1,h2,t2,m;
int main(){
	int t;cin>>t;while(t--){
		scanf("%d",&n); int t=0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),t+=a[i];
		t1=t2=m=0;
		for(int i=1;i<=n;++i)scanf("%d",&b[i]),t-=b[i],m+=abs(a[i]-b[i]);
		if(t){puts("-1");continue;}
		for(int i=1;i<=n;++i)if(a[i]>b[i])q1[++t1]=i;else if(a[i]<b[i])q2[++t2]=i;
		printf("%d\n",m>>1); m=0;
		h1=h2=1;
		while(h1<=t1){
			printf("%d %d\n",q1[h1],q2[h2]);
			a[q2[h2]]++; a[q1[h1]]--;
			if(a[q2[h2]]==b[q2[h2]])h2++;
			if(a[q1[h1]]==b[q1[h1]])h1++;
		}
		
	}
}
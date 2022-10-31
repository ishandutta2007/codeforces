#include<bits/stdc++.h>
const int N=11;
using namespace std;

int n,t,a[N],s[1<<N],ln[1<<N];

int main(){
	scanf("%d",&t);
	ln[0]=-1;
	for(int i=1;i<1<<N;i++)ln[i]=ln[i>>1]+1;
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<1<<n;i++)
			s[i]=s[i-(i&(-i))]+a[ln[i&(-i)]+1];
		int fl=0;
		for(int i=0;i<1<<n;i++)
			for(int j=0;j<1<<n;j++)
				if(!(i&j))
					for(int k=1;k<=n;k++)
						if(!((i>>(k-1))&1)&&!((j>>(k-1))&1))
							if(s[i]-s[j]==a[k])
								fl=1;
		printf("%s\n",fl?"YES":"NO");
	}
}
#include <bits/stdc++.h>

using namespace std;

int n,i,a,p,c;

int main()
{
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&a);
		if(a==1){
			p++;
			if(c<2) p+=c;
			c=0;
		}
		else{
			if(p) c++;
		}
	}
	
	printf("%d\n",p);
	
	return 0;
}
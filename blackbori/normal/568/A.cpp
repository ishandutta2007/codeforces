#include <bits/stdc++.h>

using namespace std;

bool Prime[1500001],Palin[1500001];

bool P(int i)
{
	if(i%10 == 0) return false;
	vector <int> k;
	int j;
	int c=i;
	while(i>0){
		k.push_back(i%10);
		i /= 10;
	}
	for(j=0; j<k.size()/2; j++) if(k[j] != k[k.size()-j-1]) return false;
	
	return true;
}

int main()
{
	int p,q,n,i,j,c1,c2;
	scanf("%d %d",&p,&q);
	n=1200000;
	
	Prime[1] = true;
	
	for(i=2; i<=n; i++){
		if(!Prime[i]){
			for(j=i*2; j<=n; j+=i) Prime[j] = true;
		}
	}
	
	for(i=1; i<=n; i++) Palin[i] = P(i);
	
	c1=0, c2=0;
	int ans=-1,ac1,ac2;
	for(i=1; i<=n; i++){
		c1 += (1-Prime[i]);
		c2 += Palin[i];
		if(q * c1 <= p * c2) ans = i, ac1=c1, ac2=c2;
	}
	
	if(ans != -1) printf("%d\n",ans);
	else printf("Palindromic tree is better than splay tree\n");
	
	return 0;
}
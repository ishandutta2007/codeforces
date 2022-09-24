#include <bits/stdc++.h>

using namespace std;

bool P[10001];

vector <int> v;

int main()
{
	int n,i,j;
	scanf("%d",&n);
	
	for(i=2;i<=n;i++){
		if(!P[i]){
			for(j=i+i;j<=n;j+=i) P[j]=1;
			j=i;
			while(1){
				v.push_back(j),j*=i;
				if(j>n)break;
			}
		}
	}
	
	printf("%d\n",v.size());
	for(i=0;i<v.size();i++)printf("%d ",v[i]);
	printf("\n");
	
	return 0;
}
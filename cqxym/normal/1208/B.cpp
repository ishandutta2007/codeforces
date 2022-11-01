#include<cstdio>
#include<map>
using namespace std;
int a[2001];
map<int,bool>P,Q;
int main(){
	int n,i,j,k,s=2e9;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	i=0;
	while(i<n&&Q[a[i]]==false){
		Q[a[i]]=true;
		j=n;
		while(j>i&&Q[a[j]]==false&&P[a[j]]==false){
			//printf("%d %d   ",a[j],P[a[j]]);
			P[a[j]]=true;
			j--;
		}
		/*if(Q[a[j]]==true||P[a[j]]==true){
			j++;
		}*/
		s=min(s,j-i);
		i++;
		P.clear();
	}
	printf("%d",s);
 return 0;
}
#include<bits/stdc++.h>
#define fr first
#define sc second
#define mkp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e3+5;
int n,k;
int id[N][11];
int main(){
	int i,j;
	scanf("%d%d",&n,&k);
	int s=1,c=0;
	while(s<n) s*=k,c++;
	printf("%d\n",c);
	for(i=n;i;i--){
		int x=n-i;
		for(j=1;j<=c;j++){
			id[i][j]=x%k;
			x/=k;
		}
	}
	for(i=1;i<n;i++){
		for(j=i+1;j<=n;j++){
			for(int x=1;x<=c;x++){
				if(id[i][x]>id[j][x]){
					printf("%d ",x);
					break;
				}
			}
		}
	}
	return 0;
}
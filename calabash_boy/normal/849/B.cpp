#include<bits/stdc++.h>
using namespace std;
const int MAX = 1005;
typedef long long LL;
LL y[MAX];
int n;
bool used[MAX];
bool check(int k1,int k2){
	memset(used,false,sizeof used);
	used[k1]=used[k2]= true;
	LL dx = k2-k1;
	LL dy = y[k2]-y[k1];
	for (int i=0;i<n;i++){
		if (!used[i]&&(i-k1)*dy==(y[i]-y[k1])*dx){
			used[i] = true;
		}
	}
	bool flag = false;
	LL x0,y0;
	for (int i=0;i<n;i++){
		if (flag&&!used[i]){
			if ((i-x0)*dy==(y[i]-y0)*dx){
				continue;
			}else{
				return false;
			}
		}
		if (!flag&&!used[i]){
			flag = true;
			x0=i;
			y0=y[i];
		}
	}
	if (flag){
		return true;
	}else{
		return false;
	}
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%I64d",y+i);
	}
	if (check(0,1)||check(0,2)||check(1,2)){
		printf("Yes\n");
		return 0;
	}
	printf("No\n");
	return 0;
}
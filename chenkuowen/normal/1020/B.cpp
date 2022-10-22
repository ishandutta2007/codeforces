#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX_N=1005;
int p[MAX_N];
bool mark[MAX_N];
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&p[i]);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) mark[j]=false;
		for(int j=i;;j=p[j]){
			if(mark[j]) {
				printf("%d ",j);
				break;
			}
			mark[j]=true;
		}
	}
	return 0;
}
#include<cstdio>
#include<queue>
using namespace std;
priority_queue<int> buy;
int main(){
	int n,x;
	long long ans=0LL;
	scanf("%d",&n);
	for(int k=0;k<n;k++){
		scanf("%d",&x);
		if(!buy.empty()){
			int b=buy.top();
			if(x+b>0){
				ans+=x+b;
				buy.pop();
				buy.push(-x);
			}
		}
		buy.push(-x);
	}
	printf("%I64d",ans);
	return 0;
}
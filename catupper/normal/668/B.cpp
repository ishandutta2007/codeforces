#include<cstdio>
#include<algorithm>

using namespace std;

int ans[1080000];
int n, q, qq, x;
int main(){
	int one = 0, two = 1;
	scanf("%d%d", &n, &q);
	for(int i = 0;i < q;i++){
		scanf("%d", &qq);
		if(qq == 1){
			scanf("%d", &x);
			one = (one + x) % n;if(one < 0)one += n;
			two = (two + x) % n;if(two < 0)two += n;
		}
		if(qq == 2){
			if(one % 2 == 1)one--;
			else one++;
			if(two % 2 == 1)two--;
			else two++;
		}
	}
	for(int i = 0;i < n;i += 2){
		ans[(one + i) % n] = i + 1;
	}
	for(int i = 0;i < n;i += 2){
		ans[(two + i) % n] = i + 2;
	}
	
	for(int i = 0;i < n;i++){
		printf("%d ", ans[i]);
	}puts("");
	return 0;
	
}
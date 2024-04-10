#include<cstdio>
#include<algorithm>
#include<set>

using namespace std;
int n, x;
int res;
int cnt[1080000];
int main(){
scanf("%d", &n);
	for(int i = 0;i < n;i++){
scanf("%d", &x);
		cnt[x]++;
	}
	for(int i = 0;i < 1080000;i++){
		cnt[i+1] += cnt[i] / 2;
		if(cnt[i]%2)res++;
	}
printf("%d\n", res);
	return 0;
}
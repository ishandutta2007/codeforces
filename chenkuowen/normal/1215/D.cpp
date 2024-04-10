#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+2e5;
char s[MAX_N];
int sum1=0,sum2=0,cnt1=0,cnt2=0;
int main(){
	int n; scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n/2;++i) {
		if(s[i]!='?')
			sum1+=s[i]-'0';
		else
			cnt1++;
	}
	for(int i=n/2+1;i<=n;++i){
		if(s[i]!='?')
			sum2+=s[i]-'0';
		else
			cnt2++;
	}
	if(sum1<sum2) swap(sum1,sum2),swap(cnt1,cnt2);
	if(cnt1<=cnt2){
		cnt2-=cnt1;
//		printf("<%d %d>",sum1-sum2,cnt2/2);
		if(sum1-sum2==9*(cnt2/2)) puts("Bicarp");
		else puts("Monocarp");
	}else puts("Monocarp");
	return 0;
}
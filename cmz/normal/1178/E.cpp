#include<bits/stdc++.h>
using namespace std;
char s[1100000];
int kkk;
int tot1,tot2;
char ans1[1100000],ans2[1100000];
int main(){
	ios::sync_with_stdio(false);
	scanf("%s",s+1);
	int l=1,r=strlen(s+1);
	while (1){
		if (r-l+1<4) break;
		if (s[l]==s[r]){
			ans1[tot1++]=s[l];
			ans2[tot2++]=s[r];
			l++; r--; l++; r--;
		} else 
		if (s[l+1]==s[r]){
			ans1[tot1++]=s[l+1];
			ans2[tot2++]=s[r];
			l++; r--; l++; r--;
		} else 
		if (s[l]==s[r-1]){
			ans1[tot1++]=s[l];
			ans2[tot2++]=s[r-1];
			l++; r--; l++; r--;
		} else 
		if (s[l+1]==s[r-1]){
			ans1[tot1++]=s[l+1];
			ans2[tot2++]=s[r-1];
			l++; r--; l++; r--;
		}
	}
	printf("%s", ans1);
	if(l < r) putchar(s[l]);
	reverse(ans1, ans1 + tot1);
	puts(ans1);
	return 0;
}
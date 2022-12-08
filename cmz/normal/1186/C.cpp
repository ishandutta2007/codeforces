#include<bits/stdc++.h>
const int MAXN = 2e6 + 5;
char abcd[MAXN],ff[MAXN];
int a[MAXN],b[MAXN];
int ans;
int main() {
	scanf("%s%s",abcd+1,ff+1);
	int lena = strlen(abcd+1),lenb = strlen(ff+1);
	for (int i=1; i<=lena; ++i) a[i]=abcd[i] - '0';
	int tot=0,tot2=0;
	for (int i=1; i<=lenb; ++i) b[i] = ff[i] - '0',tot2 += b[i];
	for (int i=1; i<=lenb; ++i) tot += a[i];
	if((tot%2 == 0 && tot2%2 == 0) || (tot%2==1 && tot2%2==1)) ans++;
	for (int i=2; i<=lena; ++i) {
		int r=i+lenb-1;
		if(r>lena) break;
		tot-= a[i-1];
		tot+= a[r];
		if((tot%2 == 0 && tot2%2 == 0) || (tot%2==1 && tot2%2==1)) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
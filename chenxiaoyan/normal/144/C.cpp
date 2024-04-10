#include<bits/stdc++.h>
using namespace std;
char a[100010],b[100010];
int le[100001],pre_le[26][100001],pre_q[100001];
int main(){
	int i,j,la,lb,no=0;
	scanf("%s%s",a+1,b+1);la=strlen(a+1);lb=strlen(b+1);
//	cout<<b+1<<"\n";
	for(i=1;i<=la;i++){
		for(j=0;j<26;j++)pre_le[j][i]=pre_le[j][i-1];pre_q[i]=pre_q[i-1];
		a[i]=='?'?pre_q[i]++:pre_le[a[i]-'a'][i]++;
	}
	for(i=1;i<=lb;i++)le[b[i]-'a']++;
//	for(i=1;i<=la;i++){for(j=0;j<26;j++)cout<<pre_le[j][i]<<" ";cout<<pre_q[i]<<"\n";}
//	for(i=0;i<26;i++)cout<<le[i]<<" ";puts("");
	for(i=1;i<=la-lb+1;i++){
		bool ok=true;
		for(j=0;j<26;j++)
			if(pre_le[j][i+lb-1]-pre_le[j][i-1]>le[j]){ok=false;break;}
		if(ok)no++;
//		if(ok)cout<<i<<" "<<i+lb-1<<"\n";
	}
	printf("%d",no);
	return 0;
}
/*1
bb??x???
aab
*/
/*2
ab?c
acb
*/
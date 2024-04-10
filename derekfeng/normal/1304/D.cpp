#include <bits/stdc++.h>
using namespace std;
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int T,n,now;
string s;
int ans1[200004],ans2[200004];
void MAIN(){
	cin>>n>>s;
	now=0;
	for (int i=0;i<n;i++){
		if (i==n-1 || s[i]=='<'){
			ans1[i]=now+1;
			now++;
			continue;
		}
		int j=i+1;
		for (;j<n && s[j-1]=='>';j++);
		j--;
		for (int k=j,l=1;k>=i;k--,l++) ans1[k]=l+now;
		i=j;
		now=j+1;
	}
	now=n;
	for (int i=0;i<n;i++){
		if (i==n-1 || s[i]=='>'){
			ans2[i]=now;
			now--;
			continue;
		}
		int j=i+1;
		for (;j<n && s[j-1]=='<';j++);
		j--;
		for (int k=j,l=0;k>=i;k--,l++) ans2[k]=now-l;
		i=j;
		now=n-j-1;
	}
	for (int i=0;i<n;i++) write(ans2[i]),putchar(' ');puts("");
	for (int i=0;i<n;i++) write(ans1[i]),putchar(' ');puts("");
}
int main(){
	cin>>T;
	while (T--) MAIN();
}
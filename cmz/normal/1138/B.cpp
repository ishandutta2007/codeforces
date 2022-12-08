#include <bits/stdc++.h>
using namespace std;
int n;
char c[6000],a[6000];
int cnt[2][2];
int main() {
	cin>>n;
	scanf("%s%s",c,a);
	for(int i=0; i<n; i++)cnt[c[i]-'0'][a[i]-'0']++;

	for(int a3=0; a3<=cnt[1][0]; a3++) {
		for(int a4=0; a4<=cnt[1][1]; a4++) {
			int b4=cnt[1][1]-a4;
			int b2=a3+a4-b4;
			int bb=a4+b4;
			if(b2<0||b2>cnt[0][1])continue;
			int a2=cnt[0][1]-b2;
			int a1=n/2-a2-a3-a4;
			if(a1<0||a1>cnt[0][0])continue;
			for(int i=0; i<n; i++) {
				if(a1&&c[i]=='0'&&a[i]=='0')printf("%d ",i+1),a1--;
				if(a2&&c[i]=='0'&&a[i]=='1')printf("%d ",i+1),a2--;
				if(a3&&c[i]=='1'&&a[i]=='0')printf("%d ",i+1),a3--;
				if(a4&&c[i]=='1'&&a[i]=='1')printf("%d ",i+1),a4--;
			}
			puts("");
			exit(0);
		}
	}
	puts("-1");
	exit(0);
}
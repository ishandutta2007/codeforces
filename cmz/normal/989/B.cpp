#include<bits/stdc++.h>
const int maxn=5000;
int mp[5000];
struct node {
	char now,kk;
} str[5000];
int main() {
	int n,p;
	int flag = 1;
	scanf("%d%d",&n,&p);
	getchar();
	for(int i=0; i<n; ++i)
		scanf("%c",&str[i].now);
	for(int i=0; i+p<n; ++i) {
		if((str[i].now!=str[i+p].now||((str[i].now=='.'&&str[i+p].now!='.')||(str[i].now!='.'&&str[i+p].now=='.')))||(str[i].now=='.'&&str[i+p].now=='.')) {
			flag = 0;
			break;
		} else {
			flag = 1;
		}
	}
	if(flag==0) {
		for(int i=0; i<n; ++i)
			if(str[i].now=='.') {
				str[i].now='0';
				str[i].kk='.';
			} else continue;
	} else printf("No");
	if(flag==0) {
		for(int i=0; i+p<n; ++i) {
			if(str[i].now==str[i+p].now) {
				if(str[i].kk=='.') {
					str[i].now='1';
				} else if(str[i+p].kk=='.') {
					str[i+p].now='1';
				}
			}
		}
		for(int i=0; i<n; ++i)
			printf("%c",str[i].now);
	}
	printf("\n");
	return 0;
}
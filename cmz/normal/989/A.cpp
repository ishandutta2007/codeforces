#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1024;
struct node {
	int a,b,c,cnt;
	char d;
} arr[MAX_N];
char str[MAX_N];
int main() {
	int flag = 0;
	scanf("%s",str);
	int len = strlen(str);
	for(int i=1; i<=len; ++i) {
		arr[i].d=str[i-1];
		if(arr[i].d=='A') {
			arr[i-1].a=arr[i+1].a=arr[i].a=1;
		}
		if(arr[i].d=='B') {
			arr[i-1].b=arr[i+1].b=arr[i].b=2;
		}
		if(arr[i].d=='C') {
			arr[i-1].c=arr[i+1].c=arr[i].c=3;
		}
	}
	for(int i=1; i<=len; i++) {
		arr[i].cnt=arr[i].a+arr[i].b+arr[i].c;
		if(arr[i].cnt==6) {
			flag = 1;
			break;
		}
	}
	if(flag) printf("Yes\n");
	else printf("No\n");
	return 0;
}
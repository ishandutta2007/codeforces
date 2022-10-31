#include<bits/stdc++.h>
using namespace std;
#define MAXN 100
char a [MAXN];
int n;
int main(){
	cin>>n;
	scanf("%s",a);
	for (int i=0;i<n;){
		int temp = 0;
		while (a[i]=='1'){
			temp++;
			i++;
		}
		cout<<temp;
		i++;
	}
	if (a[n-1]=='0'){
		cout<<'0';
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define MAXN 1505
#define max(a,b) (a)>(b)?(a):(b)
int ans [26][MAXN];
char a[MAXN];
int n,q;
int main(){
	scanf("%d\n",&n);
	scanf("%s",a);
	for (int i=0;i<26;i++){
	//	int temp = 0;
		for (int j=0;j<n;j++){
			int temp = 0; 
			for (int k = j;k<n;k++){
				temp+=(a[k]!=(i+'a'));
				ans[i][temp]=max(ans[i][temp],k-j+1);			
			}
		}
	}
	for (int i=0;i<26;i++){
		for (int j=0;j<n;j++){
			ans[i][j+1]=max(ans[i][j+1],ans[i][j]);
		}
	}
	cin>>q;
	for (int i=0;i<q;i++){
		char temp;
		int sum;
		scanf("%d %c",&sum,&temp);
		printf("%d\n",ans[temp-'a'][sum]==0?sum:ans[temp-'a'][sum]);
	}
	return 0;
}
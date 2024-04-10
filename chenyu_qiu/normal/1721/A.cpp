#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e6+10;
int n,m;
char a[10][10];
int main(){
	int t;
	cin>>t;
	while(t--){
		scanf("%s%s",a[1]+1,a[2]+1);
		int c[26]={0};
		int mx=0;
		for(int i=1;i<=2;i++){
			for(int j=1;j<=2;j++){
				c[a[i][j]-'a']++;
				if(c[a[i][j]-'a']>c[mx])mx=a[i][j]-'a';
			}
		}
		int ans=0;
		for(int i=0;i<26;i++){
			if(i==mx)continue;
			ans+=(c[i]+1)/2;
		}
		printf("%d\n",ans);
	}
}
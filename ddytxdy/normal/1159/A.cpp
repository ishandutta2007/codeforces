#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1000;
int n,ans,len;char c[N];
int main(){
	scanf("%d%s",&n,c);ans=0;
	for(int i=0;i<n;i++){
		if(c[i]=='-'){
			ans--;
			if(ans<0)ans=0;
		}
		else ans++;
	}
	printf("%d",ans);
	return 0;
}
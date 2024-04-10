#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[150001];
bool b[150002];
int main(){
	int n,i,ans=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	for(i=0;i<n;i++){
		if(a[i]>1&&b[a[i]-1]==false){
			b[a[i]-1]=true;
			ans++;
		}else if(b[a[i]]==false){
			b[a[i]]=true;
			ans++;
		}else if(b[a[i]+1]==false){
			b[a[i]+1]=true;
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
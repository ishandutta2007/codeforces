#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+200;
int a[maxn];
int cnt[maxn];
int ans[maxn];
bool used[maxn];
bool exist[maxn];
int n;
int main(){
	scanf("%d",&n);
	int tot=n;
	for (int i=1;i<=n;i++){
		scanf("%d",a+i);
		cnt[a[i]]++;
		used[a[i]] = true;
		ans[i]=a[i];
	}
	for (int i=1;i<=n;i++){
		if (cnt[i]==1)used[i]=exist[i]=true;
	}
	for (int i=1;i<=n;i++){
		if (cnt[i]){
			tot--;
		}
	}
	cout<<tot<<endl;
	for (int i=1,j=1;i<=n;i++){
		if (cnt[a[i]]==1){
			continue;
		}
		while (used[j])j++;
		if (ans[i]<j&&!exist[ans[i]]){
			exist[ans[i]] = true;
			continue;
		}
			
		if (j<a[i]||used[a[i]]){used[j]=true;ans[i] =j;cnt[a[i]]--;if (cnt[a[i]]==1)used[a[i]]=true;}
		else{
			used[a[i]] = true;
		}
	}
	for (int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
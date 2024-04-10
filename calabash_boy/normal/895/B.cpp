#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int a[maxn];
int n,x,k;
map<int,int> cnt;
map<int,int> cnt2;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	scanf("%d%d%d",&n,&x,&k);
	for (int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	sort(a,a+n,cmp);
	if (k==0){
		long long ans =0;
		for (int i=0;i<n;){
			int j =i;
			while (j<n&&a[j]==a[i])j++;
			cnt[a[i]/x]+=j-i;
			if (a[i]%x==0)cnt2[a[i]/x]+=j-i;
			if (a[i]%x!=0)ans+=1LL*(j-i)*(cnt[a[i]/x]-cnt2[a[i]/x]);
			i=j;
		}
		cout<<ans<<endl;
		return 0;
	}
	long long ans =0;
	for (int i=0;i<n;){
		int j=i;
		while (j<n&&a[j]==a[i]) j++;
		cnt[a[i]/x]+=j-i;
		if (a[i]%x!=0)
		ans+=1LL*(j-i)*cnt[k+a[i]/x];
		else
		ans+=1LL*(j-i)*cnt[k+a[i]/x-1];
		i=j;

	}
	cout<<ans<<endl;
}
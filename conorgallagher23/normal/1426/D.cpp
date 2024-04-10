#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+5;
int n,a[N],ans;LL s[N];
map<LL,int>cnt;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),s[i]=s[i-1]+(LL)a[i];
	cnt[0]++;
	for(int i=1,lst=0;i<=n;i++){
		if(cnt[s[i]]){
			while(lst<i-1)cnt[s[lst]]--,lst++;
			ans++;
		}	
		cnt[s[i]]++;
	}
	printf("%d\n",ans);
	return 0;
}
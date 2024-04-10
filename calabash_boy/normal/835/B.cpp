#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
char s[MAXN];
long long cont[100];
long long k;
int main(){
	scanf("%d",&k);
	scanf("%s",s);
	int len = strlen(s);
	long long sum = 0;
	for (int i=0;i<len;i++){
		sum+=s[i]-'0';
		cont[s[i]-'0']++;
	}
	if (sum>=k){
		cout<<"0"<<endl;
		return 0;
	}
	sum = k-sum;
	long long ans =0;
	for (int i = 0;i<=9;i++){
		long long maxx = cont[i]*(9-i);
		if (maxx>=sum){
			int delta = (sum+(9-i-1))/(9-i);
//			cout<<sum<<" "<<i<<" "<<delta<<endl;
			ans+=delta;
			cout<<ans<<endl;
			return 0;
		}else{
			sum-=maxx;
			ans+=cont[i];
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+100;
const int MOD = 1e9+7;
int cnt[1000];
char s1[maxn],s2[maxn];
int n;
long long ans =0;
long long bas[maxn];
long long ni[maxn];
inline long long q(long long x,long long y){
	long long res =1;
	while (y){
		if (y&1){
			res = res*x%MOD;
		}
		x = x*x%MOD;
		y>>=1;
	}
	return res;
}
inline long long calc(int tot){
	long long res = bas[tot];
	for (int i='a';i<='z';i++){
		if (cnt[i])
		res = res*q(bas[cnt[i]],MOD-2)%MOD;
	}
	return res;
}
int main(){
	bas[0]=1;
	ni[0]=1;
	for (int i=1;i<=1000000;i++){
		bas[i] = bas[i-1]*i%MOD;
		ni[i] = q(i,MOD-2);
	}
	gets(s1);
	gets(s2);
	n =strlen(s1);
	for (int i=0;i<n;i++){
		cnt[s1[i]]++;
	}
	long long temp =calc(n);
	for (int i=0;i<n;i++){
		temp = temp*ni[n-i]%MOD;
		for (int x='a';x<s2[i];x++){
			if (cnt[x]){
				ans+=temp*cnt[x]%MOD;
			}
		}
		ans%=MOD;
		temp = temp*cnt[s2[i]]%MOD;
		cnt[s2[i]]--;
		if (cnt[s2[i]]<0)break;
	}
	long long ans1 = ans;
	ans =0;
	memcpy(s2,s1,strlen(s1));
	memset(cnt,0,sizeof cnt);
	for (int i=0;i<n;i++){
		cnt[s1[i]]++;
	}
	temp =calc(n);
	for (int i=0;i<n;i++){
		temp = temp*ni[n-i]%MOD;
		for (int x='a';x<s2[i];x++){
			if (cnt[x]){
				ans+=temp*cnt[x]%MOD;
			}
		}
		ans%=MOD;
		temp = temp*cnt[s2[i]]%MOD;
		cnt[s2[i]]--;
		if (cnt[s2[i]]<0)break;

	}
	cout<<(ans1-ans+2*MOD-1)%MOD<<endl;
}
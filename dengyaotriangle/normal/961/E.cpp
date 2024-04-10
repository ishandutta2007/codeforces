#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

int n;
int a[maxn];
int bit[maxn];
pair<int,int> p[maxn];

void chg(int x,int i){
	while(i<maxn){
		bit[i]+=x;
		i+=i&(-i);
	}
}
int qry(int i){
	int ans=0;
	while(i){
		ans+=bit[i];
		i-=i&(-i);
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)p[i].first=a[i],p[i].second=i;
	sort(p+1,p+1+n,greater<pair<int,int> >());
	int cp=1;
	long long ans=0;
	for(int i=n;i>=1;i--){
		while(cp!=n+1&&p[cp].first>=i){
			chg(1,p[cp].second);
			cp++;
		}
		ans+=qry(min(a[i],n));
		if(a[i]>=i)ans--;
	}
	cout<<(ans>>1);
	return 0;
}
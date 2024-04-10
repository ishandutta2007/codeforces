#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

int n,k;
long long ans=0;
int q[maxn];
int cnt[maxn];
int nm;
int loc[maxn];

pair<int,int> an[maxn*9];
int al;
int main(){
	cin>>n>>k;
	for(int i=1;i<=k;i++)cin>>q[i];
	for(int i=k;i>=1;i--){
		loc[q[i]]=i;
	}
	nm=n;
	cnt[0]=100;
	cnt[n+1]=100;
	for(int i=k;i>=1;i--){
		if(i==loc[q[i]]){
			if(cnt[q[i]-1]==0)an[++al]=make_pair(q[i],q[i]-1);
			if(cnt[q[i]+1]==0)an[++al]=make_pair(q[i],q[i]+1);
			//if(cnt[q[i]]==0)ans++;
		}
		cnt[q[i]]++;
		if(cnt[q[i]]==1)nm--;
		
	}
	for(int i=1;i<=n;i++){
		if(loc[i]==0){
			if(i-1>0)an[++al]=make_pair(i,i-1);
			if(i+1<=n)an[++al]=make_pair(i,i+1);
			if(i-1>0)an[++al]=make_pair(i-1,i);
			if(i+1<=n)an[++al]=make_pair(i+1,i);
			an[++al]=make_pair(i,i);
		}
	}
	sort(an+1,an+1+al);
	cout<<unique(an+1,an+1+al)-an-1;
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

const int maxn=300005;

struct pt{
	long long p;
	int i;
};

int n;
pt x[maxn];
long long ans;
int ap=0;

long long absl(long long n){
	if(n<0) return 0-n;
	return n;
}

bool cmp(pt a,pt b){
	return a.p<b.p;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i].p;
		x[i].i=i;
	}
	sort(x,x+n,cmp);
	long long dis=0;
	for(int i=0;i<n;i++){
		dis+=absl(x[i].p-x[0].p);
	}
	ans=dis;
	long long ttl=1,ttr=n-1;
	for(int i=1;i<n;i++){
		//cout<<dis;
		dis-=ttr*(x[i].p-x[i-1].p);
		dis+=ttl*(x[i].p-x[i-1].p);
		ttl++;
		ttr--;
		if(dis<ans){
			ans=dis;
			ap=i;
		}
	}
	cout<<x[ap].p;
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

const int maxn=2005;

struct p{
	int v;
	int i;
};

bool cmp(p a,p b){
	if(a.v==b.v) return a.i<b.i;
	return a.v>b.v;
}

p x[maxn];
bool mk[maxn];
int o[maxn];
int oc=0;
int n,k;
int ans;

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>x[i].v;
		x[i].i=i;
	}
	sort(x,x+n,cmp);
	for(int i=0;i<k;i++){
		ans+=x[i].v;
		mk[x[i].i]=1;
	}
	cout<<ans<<endl;
	int d=1;
	for(int i=0;i<n;i++){
		if(mk[i]){
			o[oc++]=d;
			d=0;
		}
		d++;
	}
	int tc=0;
	for(int i=0;i<oc-1;i++){
		cout<<o[i]<<' ';
		tc+=o[i];
	}
	cout<<n-tc;
	return 0;
}
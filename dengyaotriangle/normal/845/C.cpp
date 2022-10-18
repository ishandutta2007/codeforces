#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

struct line{
	int l,r;
};

line x[maxn];
int y[maxn];
int m;
int n;

bool cmp(line a,line b){
	if(a.l==b.l) return a.r<b.r;
	return a.l<b.l;
}

bool lbs(int a,int b){
	return a<b;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i].l>>x[i].r;
		y[i]=x[i].r;
	}
	sort(x,x+n,cmp);
	sort(y,y+n,lbs);
	int curn=1,curl=x[0].l;
	for(int i=1;i<n;i++){
		int cl=x[i].l;
		int pl=lower_bound(y,y+n,curl,lbs)-y;
		int pr=upper_bound(y,y+n,cl-1,lbs)-y;
		curn-=max(pr-pl,0);
		curn++;
		if(curn>2){
			cout<<"NO";
			return 0;
		}
		curl=cl;
	}
	cout<<"YES";
	return 0;
}
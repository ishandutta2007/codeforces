#include<bits/stdc++.h>

using namespace std;

const int maxn=1005;

char x[maxn];
char y[maxn];
int n;
bool a[maxn];

void swp(int l,int r){
	if(l>r) swap(l,r);
	int a,b;
	a=l;b=r;
	while(a<b){
		swap(y[a],y[b]);
		a++;
		b--;
	}
}

int main(){
	cin>>x;
	n=strlen(x);
	for(int i=0;i<n;i++) y[i]=x[i];
	sort(y,y+n);
	for(int i=n-1;i>=0;i--){
		if(y[i]!=x[i]){
			swp(0,i);
			a[i]=1;
		}
	}
	for(int i=0;i<n;i++) cout<<a[i]<<' ';
	return 0;
}
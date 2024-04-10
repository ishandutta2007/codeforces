#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s[n];
	int t[n],d[n],g[n];
	for(int z=0;z<n;z++){
		int a;
		t[z]=0;d[z]=0;g[z]=0;
		cin>>a>>s[z];
		while(a-->0){
			int p,q,r,k=1;
			scanf("%d-%d-%d",&p,&q,&r);
			p=(p*100+q)*100+r;
			q=p;r=p%10;p/=10;
			for(int i=0;i<5;i++){
				if(r!=p%10) {k=0;break;}
				r=p%10;
				p/=10;
			}
			if(k){t[z]++;continue;}
			p=q;r=p%10;p/=10;k=1;
			for(int i=0;i<5;i++){
				if(r>=p%10) {k=0;break;}
				r=p%10;
				p/=10;
			}
			if(k)d[z]++;
			else g[z]++;
		}
	}
	int tm=t[0],dm=d[0],gm=g[0];
	for(int i=1;i<n;i++){
		if(t[i]>tm)tm=t[i];
		if(d[i]>dm)dm=d[i];
		if(g[i]>gm)gm=g[i];
	}
	cout<<"If you want to call a taxi, you should call: ";
	int c=0;
	for(int i=0;i<n;i++)
		if(t[i]==tm){
			if(c>0)cout<<", ";
			cout<<s[i];
			c=1;
		}
	cout<<".\n";
	cout<<"If you want to order a pizza, you should call: ";
	c=0;
	for(int i=0;i<n;i++)
		if(d[i]==dm){
			if(c>0)cout<<", ";
			cout<<s[i];
			c=1;
		}
	cout<<".\n";
	cout<<"If you want to go to a cafe with a wonderful girl, you should call: ";
	c=0;
	for(int i=0;i<n;i++)
		if(g[i]==gm){
			if(c>0)cout<<", ";
			cout<<s[i];
			c=1;
		}
	cout<<".\n";
}
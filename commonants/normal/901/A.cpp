#include<bits/stdc++.h>

using namespace std;

const int MX=200005;

int h,a[MX];
int hed[MX];
int main(){
	ios::sync_with_stdio(false);
	cin>>h;
	for(int i=0;i<=h;i++)cin>>a[i];
	int it=-1;
	for(int i=1;i<=h;i++)if(a[i]>1&&a[i-1]>1){it=i;break;}
	if(it==-1)cout<<"perfect"<<endl;
	else{
		cout<<"ambiguous"<<endl;
		hed[0]=1;
		for(int i=1;i<=h+1;i++)hed[i]=hed[i-1]+a[i-1];
		for(int i=0;i<=h;i++)
			for(int j=1;j<=a[i];j++)
				cout<<(i?hed[i-1]:0)<<' ';
		cout<<endl;
		for(int i=0;i<=h;i++)
			for(int j=1;j<=a[i];j++)
				cout<<(i?(i==it&&j>1?hed[i]-1:hed[i-1]):0)<<' ';
		cout<<endl;
	}
	return 0;
}
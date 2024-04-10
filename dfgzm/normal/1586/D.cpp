#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
int i,j,k,n,m,T,a[110];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(i=n;i>=1;i--){
		cout<<"? ";
		for(j=2;j<=n;j++)cout<<i<<' ';
		cout<<1;
		cout<<endl;
		int p;cin>>p;
		if(p){
			a[n]=i;
			break;
		}
	}
	if(!a[n])a[n]=1;
	for(i=1;i<a[n];i++){
		cout<<"? ";
		for(j=1;j<n;j++)cout<<a[n]-i+1<<' ';
		cout<<1<<endl;
		int p;cin>>p;
		a[p]=i;
	}
	for(i=a[n]+1;i<=n;i++){
		cout<<"? ";
		for(j=1;j<n;j++)cout<<1<<' ';
		cout<<i-a[n]+1<<endl;
		int p;cin>>p;
		a[p]=i;
	}
	cout<<"!";
	for(i=1;i<=n;i++)cout<<' '<<a[i];cout<<endl;
}
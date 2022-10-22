#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;
char a[3][N];
int c[3];
inline void work(char *a,char *b,char f){
	int c=0,p=0;
	for(int i=1;i<=2*n;i++){
		c++;
		if(a[i]!=f){
			cout<<a[i];
			continue;
		}
		while(p<2*n&&b[p+1]!=f){
			p++;c++;
			cout<<b[p];
		}
		cout<<f;p++;
	}
	while(p<2*n){
		p++;c++;
		cout<<b[p];
	}
	while(c<3*n){
		c++;
		cout<<0;
	}
	cout<<endl;
	return;
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		for(i=0;i<3;i++) cin>>(a[i]+1);
		c[0]=c[1]=c[2]=0;
		for(i=0;i<3;i++){
			for(j=1;j<=2*n;j++)
				c[i]+=(a[i][j]=='1');
		}
		bool f=0;
		for(i=0;i<3;i++){
			for(j=i+1;j<3;j++){
				if(c[i]>=n&&c[j]>=n){
					work(a[i],a[j],'1');
					f=1;break;
				}
				if(c[i]<=n&&c[j]<=n){
					work(a[i],a[j],'0');
					f=1;break;
				}
			}
			if(f==1) break;
		}
		for(i=1;i<=2*n;i++) a[0][i]=a[1][i]=a[2][i]=0;
	}
	return 0;
}
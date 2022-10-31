#include<bits/stdc++.h>
const int N=105; 
using namespace std;

int l[N],a[N];
int f[N][2][N];
int ans=-1e9;

int gp(int k,int p){
	return p?a[k]-l[k]:a[k]+l[k];
}

int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>l[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<n;j++)
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]),swap(l[j],l[j+1]);
	a[0]=-1e9;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++)
			for(int k=0;k<2;k++){
				ans=max(ans,f[i][k][j]);
				int nw=a[j]+k*l[j],x,y,z=-1e9;
				for(int o=i+1;o<=n;o++)
					for(int m=0;m<2;m++){
						int nt=a[o]+m*l[o];
						if(nt>z)z=nt,x=m,y=o;
						f[o][x][y]=max(f[o][x][y],f[i][k][j]+min(l[o],nt-nw)+z-nt);
					}
			}
	cout<<ans<<endl;
}
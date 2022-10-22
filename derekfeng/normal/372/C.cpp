#include <bits/stdc++.h>
using namespace std;
#define left my_left
#define right my_right
const int inf=(int)1e9;
const int N=600010;
int a[N],b[N],t[N];
int f[N],left[N],right[N];
int main(){
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=0;i<m;i++) scanf("%d%d%d",a+i,b+i,t+i);
	long long add=0;
	for (int i=0;i<m;i++) add+=b[i]; 
	for (int i=0;i<m;i++)
		for (int j=i+1;j<m;j++)
			if(t[i]>t[j]){
				int tmp;
				tmp=t[i];t[i]=t[j];t[j]=tmp;
				tmp=a[i];a[i]=a[j];a[j]=tmp;
			}
	for (int i=1;i<=n;i++) f[i]=0;
	int when=0;
	for (int ev=0;ev<m;ev++){
		long long units=(long long)d*(t[ev]-when);
		if (units>n) units=n;
		int len=2*units+1;
		int nn=((n+len-1)/len)*len;
		for (int i=n+1;i<=nn;i++) f[i]=inf;
		for (int i=1;i<=nn;i++){
			if((i-1)%len==0) left[i]=inf;
			else left[i]=left[i-1];
			if (f[i]<left[i]) left[i]=f[i];
		}
		for (int i=nn;i>=1;i--){
			if (i%len==0) right[i]=inf;
			else right[i]=right[i+1];
			if (f[i]<right[i]) right[i]=f[i];
		}
		for (int i=1;i<=n;i++){
			int lg=i-units;
			int rg=i+units;
			if (lg<1) lg=1;
			if (rg>nn) rg=nn;
			if (lg==1) f[i]=left[rg];else
			if (rg==nn) f[i]=right[lg];else{
				f[i]=left[rg];
				if (right[lg]<f[i]) f[i]=right[lg];
			}
		}
		for (int i=1;i<=n;i++){
			int diff=i-a[ev];
			if (diff<0) diff=-diff;
			f[i]+=diff;
		}
		when=t[ev];
	}
	int ans=f[1];
	for (int i=1;i<=n;i++)
		if (f[i]<ans) ans=f[i];
	cout<<(add-ans)<<endl;
	return 0;
}
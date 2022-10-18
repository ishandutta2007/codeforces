#include<bits/stdc++.h>

using namespace std;

const int maxn=1000006;

int n,m;
int a[maxn];
int loc[maxn],foc[maxn];
int okm[maxn],okf[maxn];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(foc,0x3f,sizeof(foc));
	memset(loc,0xc0,sizeof(loc));
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(foc[a[i]]==0x3f3f3f3f){
			foc[a[i]]=i;
		}
		loc[a[i]]=i;
	}
	memset(okf,0x3f,sizeof(okf));
	memset(okm,0xc0,sizeof(okm));
	okm[m+1]=n+1;
	loc[0]=foc[0]=0;
	foc[m+1]=loc[m+1]=n+1;
	for(int i=m;i>=0;i--){
		if(loc[i]==0xc0c0c0c0){
			okm[i]=okm[i+1];
		}else if(loc[i]<okm[i+1]){
			okm[i]=foc[i];
		}else{
			break;
		}
	}
	okf[0]=0;
	for(int i=1;i<=m+1;i++){
		if(foc[i]==0x3f3f3f3f){
			okf[i]=okf[i-1];
		}else if(foc[i]>okf[i-1]){
			okf[i]=loc[i];
		}else{
			break;
		}
	}
	int p2=0;
	for(int i=0;i<=m+1;i++){
		while((okm[p2]<okf[i]||p2<i+2)&&p2<=m+1) p2++;
		if(p2<=m+1) ans+=m+1-p2+1;
	}
	cout<<ans;
	return 0;
}
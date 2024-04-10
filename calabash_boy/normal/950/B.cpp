#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int a[maxn],b[maxn],na,nb;
int main(){
	scanf("%d%d",&na,&nb);
	for (int i=0;i<na;i++){
		scanf("%d",a+i);
	}
	for (int i=0;i<nb;i++){
		scanf("%d",b+i);
	}
	int ans =0;
	for (int i=0,j=0,suma=a[0],sumb=b[0];i<na,j<nb;){
		if (suma==sumb){
			ans++;
			suma=a[++i];
			sumb=b[++j];
		}else if (suma<sumb){
			suma+=a[++i];
		}else {
			sumb+=b[++j];
		}
	}
	cout<<ans<<endl;
	return 0;
}
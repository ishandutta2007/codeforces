#include<bits/stdc++.h>

using namespace std;

const int maxn=300005;

long long a[maxn],b[maxn];
long long suma,sumb;
int n,m;
int ans;
int pa,pb;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		suma+=a[i];
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>b[i];
		sumb+=b[i];
	}
	if(suma!=sumb){
		cout<<-1;
		return 0;
	}
	suma=0;sumb=0;
	while(true){
		if(pa==n&&pb==m) break;
		if(suma==sumb){
			ans++;
			suma=0;
			sumb=0;
			suma+=a[pa++];
			sumb+=b[pb++];
		}else{
			if(suma>sumb){
				sumb+=b[pb++];
			}else{
				suma+=a[pa++];
			}
		}
	}
	cout<<ans;
	return 0;
}
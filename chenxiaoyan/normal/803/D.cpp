/*








*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=1000000;
int n,m;
char a[N+5];
vector<int> sp;
bool chk(int lim){
	int now=0;
	for(int i=1;i<=m;i++){
		int j=now;
		while(j<sp.size()&&sp[j]-sp[now]<=lim)j++;
		j--;
		now=j;
//		cout<<lim<<" "<<now<<"\n";
	}
	return now==sp.size()-1;
}
int main(){
	cin>>m;scanf(" %[^\n]",a+1);
	n=strlen(a+1);
	sp.pb(0);
	for(int i=1;i<=n;i++)if(a[i]==' '||a[i]=='-')sp.pb(i);
	sp.pb(n);
	int ans=n;
	for(int i=20;~i;i--)if(ans-(1<<i)>=0&&chk(ans-(1<<i)))ans-=1<<i;
	cout<<ans;
	return 0;
}
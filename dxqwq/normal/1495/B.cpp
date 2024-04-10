#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=100010;
int n,a[maxn],len_up,len_down;
int dp1[maxn],dp2[maxn],len_max;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>a[i-1]) dp1[i]=dp1[i-1]+1;
		else dp1[i]=1;
		if(a[i]<a[i-1]) dp2[i]=dp2[i-1]+1;
		else dp2[i]=1;
		len_up=max(len_up,dp1[i]);
		len_down=max(len_up,dp2[i]);
	}
	len_max=max(len_up,len_down);
	bool f_up=false,f_down=false;
	int p_up,p_down;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(dp1[i]==len_max){
			f_up=true;
			cnt++;
			p_up=i;
		}
		if(dp2[i]==len_max){
			f_down=true;
			cnt++;
			p_down=i;
		} 
	}
	if(f_up&&f_down&&cnt==2&&p_up==p_down-len_max+1&&len_max%2) cout<<1<<endl; 
	else cout<<0<<endl;	
	return 0;
}
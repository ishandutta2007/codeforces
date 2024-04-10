#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int N=400005;
const ll inf=0x3f3f3f3f;
const ll mod=998244353;
int n,m;
int cnt1,cnt2;
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		int x;cin>>x;
		if(x==1) cnt1++;
		else cnt2++;
	}
	if(cnt2){
		cout<<"2 ";
		cnt2--;
		i=2;
	}
	else if(cnt1>1){
		cout<<"1 1 ";
		cnt1-=2;
		i=3;
	}
	else{
		cout<<"1 ";
		return 0;
	}
	int tmp=2;
	for(;i<=n;i++){
		if((tmp&1)&&cnt2){
			cout<<"2 ";
			cnt2--;tmp+=2;
		}
		else if(cnt1){
			cout<<"1 ";
			cnt1--;tmp++;
		}
		else{
			cout<<"2 ";
			cnt2--;tmp+=2;
		}
	}
	return 0;
}
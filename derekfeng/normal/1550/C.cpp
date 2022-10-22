#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
ll ans;
int T,n,a[200004];
vector<pii>st1,st2;
int bit1[200004],bit2[200004],pl[200004];
int got1(int id){
	int mn=0;
	for(;id;id-=(id&-id))mn=max(mn,bit1[id]);
	return mn;
}
void upd1(int id,int x){
	for(;id<=n;id+=(id&-id))bit1[id]=max(bit1[id],x);
}
int got2(int id){
	int mn=0;
	for(;id;id-=(id&-id))mn=max(mn,bit2[id]);
	return mn;
}
void upd2(int id,int x){
	for(;id<=n;id+=(id&-id))bit2[id]=max(bit2[id],x);
}
int main(){
	cin>>T;
	while(T--){
		ans=0;vector<int>all;
		cin>>n;
		int now=0;
		for(int i=1;i<=n;i++)cin>>a[i],all.push_back(a[i]),bit1[i]=bit2[i]=pl[i]=0;
		sort(all.begin(),all.end());
		for(int i=1;i<=n;i++){
			int lb=lower_bound(all.begin(),all.end(),a[i])-all.begin()+1;
			int fs=got2(lb);now=max(now,fs);
			fs=got1(lb),upd2(lb,fs);
			upd1(lb,i);
			pl[i]=now;
		}
		for(int i=1;i<=n;i++)bit1[i]=bit2[i]=0;
		now=0;
		for(int i=1;i<=n;i++){
			int lb=lower_bound(all.begin(),all.end(),a[i])-all.begin()+1;
			lb=n-lb+1;
			int fs=got2(lb);now=max(now,fs);
			fs=got1(lb),upd2(lb,fs);
			upd1(lb,i);
			pl[i]=max(pl[i],now);
			ans+=(ll)i-pl[i];
		}
		cout<<ans<<"\n";
	}
}
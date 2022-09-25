#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) loopii(i,0,a)
#define loopii(i,b,a) for(int i=b; i<(a); i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pow2(x) (1ll<<(x))
 
using namespace std;

const int Mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	int p[n];
	int a[2]={0,0};
	vector<pii> vec;
	loop(n){
		cin >> p[i];
		if(p[i]==0){
			continue;
		}
		vec.push_back(make_pair(i,p[i]%2));
		if(p[i]%2==1) a[1]++;
		else a[0]++;
	}
	if(vec.empty()){
		if(n==1) cout << "0\n";
		else cout << "1\n";
		return 0;
	}
	a[0]=n/2-a[0];
	a[1]=ceil(n/2.0)-a[1];
	vector<int> vec0,vec1;
	pii corner1,corner2;
	corner1=corner2=make_pair(0,-1);
	int cnt[2],ans=0;
	cnt[0]=cnt[1]=0;
	loop(vec.size()+1){
		if(i==0) corner1=make_pair(vec[0].first,vec[0].second);
		else if(i==vec.size()) corner2=make_pair(n-1-vec[i-1].first,vec[i-1].second);
		else{
			if(vec[i-1].second==1&&vec[i].second==1) vec1.push_back(vec[i].first-vec[i-1].first-1);
			else if(vec[i-1].second==0&&vec[i].second==0) vec0.push_back(vec[i].first-vec[i-1].first-1);
			else ans++;
		}
	}
	cnt[corner1.second]+=corner1.first;
	cnt[corner2.second]+=corner2.first;
	loop(vec0.size()) cnt[0]+=vec0[i];
	loop(vec1.size()) cnt[1]+=vec1[i];
	if(a[0]>=cnt[0]&&a[1]>=cnt[1]){
		cout << ans << "\n";
		return 0;
	}
	int x=0,y=-1;
	if(corner1.first>corner2.first) swap(corner1,corner2);
	if(a[0]<cnt[0]){
		sort(vec0.begin(),vec0.end());
		loop(vec0.size()){
			if(x+vec0[i]>a[0]){
				y=i;
				a[0]=a[0]-x;
				break;
			}
			x+=vec0[i];
		}
		if(y==-1){
			y=vec0.size();
			a[0]=a[0]-x;
		}
		ans+=2*(vec0.size()-y);
		if(corner1.second==0){
			if(corner1.first<=a[0]) a[0]=a[0]-corner1.first;
			else ans++;
		}
		if(corner2.second==0){
			if(corner2.first<=a[0]) a[0]=a[0]-corner2.first;
			else ans++;
		}
	}
	if(a[1]<cnt[1]){
		sort(vec1.begin(),vec1.end());
		loop(vec1.size()){
			if(x+vec1[i]>a[1]){
				y=i;
				a[1]=a[1]-x;
				break;
			}
			x+=vec1[i];
		}
		if(y==-1){
			y=vec1.size();
			a[1]=a[1]-x;
		}
		ans+=2*(vec1.size()-y);
		if(corner1.second==1){
			if(corner1.first<=a[1]) a[1]=a[1]-corner1.first;
			else ans++;
		}
		if(corner2.second==1){
			if(corner2.first<=a[1]) a[1]=a[1]-corner2.first;
			else ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}
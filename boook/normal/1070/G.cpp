#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
const int MAX=1e2+5;

int n,m,mi,ma;
int pos[MAX];
int arr[MAX];

vector<int> lef(int ed){
	vector<int> v;
	int now=arr[ma],nm=pos[ma];
	for(int i=ma-1;i>ed;i--){
		if(pos[i]){
			if(now<arr[i]){
				now=arr[i];
				v.eb(nm);
				nm=pos[i];
			}
			else
				v.eb(pos[i]);
		}
		else{
			now+=arr[i];
			if(now<0)	return v;
		}
	}
	if(ma>ed)
		v.eb(nm);
	now=arr[mi],nm=pos[mi];

	for(int i=mi+1;i<=ed;i++){
		if(pos[i]){
			if(now<arr[i]){
				now=arr[i];
				v.eb(nm);
				nm=pos[i];
			}
			else
				v.eb(pos[i]);
		}
		else{
			now+=arr[i];
			if(now<0)	return v;
		}
	}
	v.eb(nm);
	return v;
}
vector<int> rig(int ed){
	vector<int> v;
	int now=arr[mi],nm=pos[mi];
	for(int i=mi+1;i<ed;i++){
		if(pos[i]){
			if(now<arr[i]){
				now=arr[i];
				v.eb(nm);
				nm=pos[i];
			}
			else
				v.eb(pos[i]);
		}
		else{
			now+=arr[i];
			if(now<0)	return v;
		}
	}
	if(mi<ed)
		v.eb(nm);
	now=arr[ma],nm=pos[ma];
	for(int i=ma-1;i>=ed;i--){
		if(pos[i]){
			if(now<arr[i]){
				now=arr[i];
				v.eb(nm);
				nm=pos[i];
			}
			else
				v.eb(pos[i]);
		}
		else{
			now+=arr[i];
			if(now<0)	return v;
		}
	}
	v.eb(nm);
	return v;
}
vector<int> pro(int ed){
	vector<int> v=lef(ed);
	if(v.size()==m)	return v;
	v=rig(ed);
	return v;
}
int main(){
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> n >> m;
	mi=n+1; ma=0;
	for(int i=1;i<=m;i++){
		int s,h;	cin >> s >> h;
		pos[s]=i;
		arr[s]=h;
		mi=min(mi,s);
		ma=max(ma,s);
	}
	for(int i=1;i<=n;i++){
		int x;	cin >> x;
		if(!arr[i])	arr[i]=x;
	}
	for(int i=mi;i<=ma;i++){
		vector<int> v=pro(i);
		reverse(v.begin() , v.end());
		if(v.size()==m){
			cout << i << '\n';
			for(int j:v)	cout<<j<< ' ';
			cout<< '\n';
			return 0;
		}
	}
	cout <<"-1\n";
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
 
const int N=2005;

int parent[2005];
int sz[2005];

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}




int n;
int x[N];
int y[N];
int a[N];
bool val[N];

bool comp(int i, int j){
	return (x[i]*y[j]-x[j]*y[i]>0);
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	int xx=1e18;
	int yy=1e18;
	int ind=-1;
	for(int i=1; i<=n; i++){
		cin>>x[i]>>y[i]>>a[i];
		if(a[i]==i){
			val[i]=0;
			continue;
		}
		else{
			val[i]=1;
			make_set(i);
		}
		if(y[i]<yy){
			yy=y[i];
			xx=x[i];
			ind=i;
			continue;
		}
		if(y[i]==yy && x[i]<xx){
			ind=i;
			xx=x[i];
		}
	}
	
	if(ind==-1){
		cout<<0;
		return 0;
	}
	
	vector<int>vec;
	
	for(int i=1; i<=n; i++){
		x[i]-=xx;
		y[i]-=yy;
		if(val[i]==0 || i==ind){
			continue;
		}
		vec.pb(i);
	}
	
	sort(vec.begin(), vec.end(), comp);

	for(int i=1; i<=n; i++){
		if(a[i]==i || i==ind){
			continue;
		}
		union_sets(i, a[i]);
	}
	
	int sz=vec.size();
	vector<pair<int, int>>fin;
	
	for(int i=0; i<sz-1; i++){
		if(find_set(vec[i])!=find_set(vec[i+1])){
			union_sets(vec[i], vec[i+1]);
			fin.pb({vec[i], vec[i+1]});
			swap(a[vec[i]], a[vec[i+1]]);
		}
	}

	for(int i=1; i<=n; i++){
		if(i==ind || val[i]==0){
			continue;
		}
		fin.pb({ind, a[ind]});
		a[ind]=a[a[ind]];
	}
	cout<<fin.size()<<endl;
	
	for(auto u:fin){
		
		cout<<u.f<<" "<<u.s<<endl;
		
	}
	
	return 0;
}
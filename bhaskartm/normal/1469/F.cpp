#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
 
#define f first
#define s second
#define pb push_back
#define endl '\n'
 
const int N=2e5+1;
 
int t[800005];
int lazy[800005];
 
 
void push(int v, int tl, int tr) {
	int tm=(tl+tr)/2;
    t[v*2] += lazy[v]*(tm-tl+1);
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v]*(tr-tm);
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}
 
void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += addend*(tr-tl+1);
        lazy[v] += addend;
    } else {
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = (t[v*2] + t[v*2+1]);
    }
}
 
int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l <= tl && tr <= r)
        return t[v];
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, min(r, tm))+query(v*2+1, tm+1, tr, max(l, tm+1), r);
}
 
int f(int v, int tl, int tr){
	push(v, tl, tr);
	if(t[v]==0){
		return -1;
	}
	if(tl==tr){
		return tl;
	}
	int tm=(tl+tr)/2;
	if(t[2*v]>0){
		return f(2*v, tl, tm);
	}
	else{
		return f(2*v+1, tm+1, tr);
	}
}
 
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long int n, k;
	cin>>n>>k;
	long long int l[n];
	long long int sum=1;
	vector<int>v;
	for(int i=0; i<n; i++){
		cin>>l[i];
		sum+=(l[i]-2);
		v.pb(l[i]);
	}
	if(sum<k){
		cout<<-1;
		return 0;
	}	
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int lo=0;
	int hi=2e5;
	int ans=2e5;
	while(lo<=hi){
		int mid=(lo+hi)/2;
		for(int i=0; i<800005; i++){
			t[i]=0;
			lazy[i]=0;
		}
		bool che=0;
		update(1, 0, N, 0, 0, 1);
		for(int i=0; i<v.size(); i++){
			int u=v[i];
			int val=query(1, 0, N, 0, mid);
			if(val>=k){
				che=1;
				break;
			}
			
		
			int ind=f(1, 0, N);
			if(ind==-1 || ind>=mid-1){
				che=0;
				break;
			}
			update(1, 0, N, ind, ind, -1);
			if(u%2==1){
				update(1, 0, N, ind+2, min(mid, ind+1+u/2), 2);
			}
			else{
				update(1, 0, N, ind+2, min(mid, ind+1+u/2), 2);
				if(ind+1+u/2<N){
					update(1, 0, N, ind+1+u/2, ind+1+u/2, -1);
				}
			}
			if(i==v.size()-1){
				val=query(1, 0, N, 0, mid);
				if(val>=k){
					che=1;
					break;
				}
			}
		}
		if(che){
			ans=mid;
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
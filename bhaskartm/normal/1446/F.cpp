#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define EPS 1e-9
#define pi acos(-1)
#define T long double
int n, k;
const int N=2e5+5;
int t[4*N+5];
int x[N];
int y[N];




pair<T, int>p[N]; 

int vis[N];




int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}


void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] += new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}





int f(T r){
	int top=0;
	int vals=(n*(n-1))/2;
	for(int i=0; i<n; i++){
		vis[i]=0;
	}
	for(int i=0; i<4*N+5; i++){
		t[i]=0;
	}
	for(int i=0; i<n; i++){
		T d=sqrt(x[i]*x[i]+y[i]*y[i]);
		if(d>r+EPS){
			T ang1=atan2(y[i], x[i]);
			T ang2=acos(r/d);
			T l=ang1-ang2;
			T r=ang1+ang2;
			if(l<0){
				l+=2*pi;
			}
			if(l>2*pi){
				l-=2*pi;
			}
			if(r<0){
				r+=2*pi;
			}
			if(r>2*pi){
				r-=2*pi;
			}
			p[++top]={l, i};
			p[++top]={r, i};
		}
	}
	sort(p+1, p+top+1);
	
	
	for(int i=1; i<=top; i++){
		int id=p[i].s;
		if(!vis[id]){
			vis[id]=i;
			update(1, 0, N, i, 1);
		}
		else{
			vals-=sum(1, 0, N, vis[id]+1, i);

			update(1, 0, N, vis[id], -1);
		}
	}
	return vals;
}






 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	for(int i=0; i<n; i++){
		cin>>x[i]>>y[i];
	}
	T lo=0;
	T hi=2e5;
	for(int i=0; i<50; i++){
		T mid=(lo+hi)/2;
		
		int x=f(mid);

		if(x>=k){
			hi=mid;
		}
		else{
			lo=mid;
		}
	}
	cout<<fixed<<setprecision(20)<<lo;
	return 0;
}
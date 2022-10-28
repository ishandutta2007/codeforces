#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'
 
int n, q;
string st;
const int N=1e5+5;
vector<vector<int>>t;


vector<int> merge(vector<int>l, vector<int>r){
	vector<int>res;
	res.resize(6);
	for(int i=0; i<3; i++){
		res[i]=l[i]+r[i];
	}
	res[3]=min(l[0]+r[3], l[3]+r[1]);
	res[4]=min(l[1]+r[4], l[4]+r[2]);
	res[5]=1e6;
	res[5]=min(res[5], l[0]+r[5]);
	res[5]=min(res[5], l[5]+r[2]);
	res[5]=min(res[5], l[3]+r[4]);
	return res;
}

vector<int> query(int v, int tl, int tr, int l, int r) {
    if (l > r){ 
        vector<int>res;
        for(int i=0; i<6; i++){
        	res.pb(0);
        }
        return res;
    }
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return merge(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
}


void update(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        if(st[pos]=='a'){
        	t[v][0]=1;
        	t[v][1]=0;
        	t[v][2]=0;
        }
        else if(st[pos]=='b'){
        	t[v][0]=0;
        	t[v][1]=1;
        	t[v][2]=0;
        }
        else{
        	t[v][0]=0;
        	t[v][1]=0;
        	t[v][2]=1;
        }
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos);
        else
            update(v*2+1, tm+1, tr, pos);
        t[v] = merge(t[v*2], t[v*2+1]);
    }
}

 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>q;
	cin>>st;
	
	t.resize(4*N+5);
	
	for(int i=0; i<4*N+5; i++){
		t[i].resize(6);
	}
	
	for(int i=0; i<n; i++){
		update(1, 0, n-1, i);
	}
	
	for(int i=0; i<q; i++){
		int ind;
		char c;
		cin>>ind>>c;
		ind--;
		st[ind]=c;
		update(1, 0, n-1, ind);
		vector<int>res=query(1, 0, n-1, 0, n-1);
		cout<<res[5]<<endl;
	}
	
	
	return 0;
}
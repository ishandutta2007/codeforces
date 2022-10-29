#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

int t[800020];

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
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}


main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	string st;
	cin>>st;
	string st2;
	st2=st;
	reverse(st2.begin(), st2.end());
	vector<vector<int>>v1;
	vector<vector<int>>v2;
	v1.resize(26);
	v2.resize(26);
	for(int i=0; i<st.size(); i++){
		v1[(st[i]-'a')].pb(i);
	}
	for(int i=0; i<st2.size(); i++){
		v2[(st2[i]-'a')].pb(i);
	}
	int arr[n];
	for(int i=0; i<26; i++){
		for(int j=0; j<v1[i].size(); j++){
			arr[v2[i][j]]=v1[i][j];
		}
	}
	int ans=0;
	for(int i=0; i<n; i++){
		ans+=sum(1, 0, n+1, arr[i], n+1);
		update(1, 0, n+1, arr[i], 1);
	}
	cout<<ans;
	return 0;
}
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 5e5+5;

int n, a[MM], dp[MM];
int l[MM], r[MM], cnt[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		if(!l[a[i]])
			l[a[i]] = i;
		r[a[i]] = i;
	}
	for(int i = n; i; i--){
		dp[i] = dp[i+1];
		cnt[a[i]]++;
		dp[i] = max(dp[i], cnt[a[i]]);
		if(i == l[a[i]])
			dp[i] = max(dp[i], cnt[a[i]]+dp[r[a[i]]+1]);
	}
	
	cout<<n-dp[1]<<'\n';
}
/*
when a[i] is not the first occurence but we keep all of this colour,
the previous a[i]s need to get moved to the end to rejoin these
and to let a[i]s rejoin, move remaning books to the end behind the moved a[i]s
*/
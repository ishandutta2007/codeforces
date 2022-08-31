#include <bits/stdc++.h>
using namespace std;
int x[45],y[45];
int main(){
	int n; cin>>n;
	n = 4*n+1;
	for(int i=1;i<=n;++i){
		cin>>x[i]>>y[i];
	}

	for(int j=1;j<=n;++j){
		int min_x = 105, max_x = -105;
		int min_y = 105, max_y = -105;
		for(int i=1;i<=n;++i) if(i!=j){
			min_x = min(min_x,x[i]);
			max_x = max(max_x,x[i]);

			min_y = min(min_y,y[i]);
			max_y = max(max_y,y[i]);
		}
		if(max_x - min_x != max_y - min_y)
			continue;
		int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
		bool bad = 0;
		for(int i=1;i<=n;++i) if(i!=j){
			if(x[i] == max_x) ++cnt1;
			if(x[i] == min_x) ++cnt2;
			if(y[i] == max_y) ++cnt3;
			if(y[i] == min_y) ++cnt4;
			if(x[i] != max_x && x[i] != min_x
				&& y[i] != max_y && y[i] != min_y)
				bad = 1;
		}

		if(bad || min({cnt1,cnt2,cnt3,cnt4}) < n/4) continue;
		if(x[j] > max_x || x[j] < min_x
			|| y[j] > max_y || y[j] < min_y)
			return cout<<x[j]<<' '<<y[j],0;

		if(x[j] != max_x && x[j] != min_x
			&& y[j] != max_y && y[j] != min_y)
			return cout<<x[j]<<' '<<y[j],0;
	}
}
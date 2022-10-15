#include <bits/stdc++.h>

using namespace std;


long long fact[20];


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long q;
	cin >> q;
	
	fact[0] = 1;
	for(long long i = 1;i <= 19;i++){
		fact[i] = fact[i-1] * i;
	} 
	
	while(q--){
		long long x;
		cin >> x;
		vector<int> v;
		
		for(long long i = 2;x != 0;i++){
			v.push_back(x%i);
			x/=i;
			
		}
		
		sort(v.begin(),v.end());
		
		long long ovAns = 0;
		for(int rmvIndex = 0;rmvIndex < v.size();rmvIndex++){
			if(v[rmvIndex] == 0) continue;
			if(rmvIndex != (v.size()-1) && v[rmvIndex] == v[rmvIndex+1]) continue; 
			long long ans = 1;
			
			long long cnt[23];
			fill(cnt,cnt+23,0);
			for(int i = 0;i < v.size();i++){
				if(i != rmvIndex) cnt[v[i]]++;
			}
			
			long long pre = cnt[0] + cnt[1];
			for(long long i = 0;i < v.size() - 1;i++){
				//cout << (long long) (pre - i) << " ";
				ans *= (pre - i);
				
				pre += cnt[i+2];
			}
			//cout << "\n";
			
			for(int i = 0;i < 23;i++){
				ans /= fact[cnt[i]];
			}
			
			ovAns += ans;
			
		}
		
		cout << (long long) (ovAns - 1) << "\n";
		
	}
}
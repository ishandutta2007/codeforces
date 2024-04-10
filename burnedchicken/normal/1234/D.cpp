#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) for(long long i=0; i<a; i++)
#define IOS ios_base::sync_with_stdio(0),cin.tie(0)
 
using namespace std;
 
int main(){
	IOS;
	string s;
	int q,x,l,r,t,ans;
	char c;
	cin >> s >> q;
	vector<int> vec[18][26];
	int arr[26];
	loop(26) arr[i]=0;
	loop(18){
		if(i==0){
			for(int j=0; j<s.size(); j++){
				for(int k=0; k<26; k++){
					if(k==s[j]-97) vec[0][k].push_back(1);
					else vec[0][k].push_back(0);
				}
			}
			continue;
		}
		for(int j=0; j<vec[i-1][0].size()/2; j++){
			for(int k=0; k<26; k++){
				vec[i][k].push_back(vec[i-1][k].at(2*j)+vec[i-1][k].at(2*j+1));
			}
		}
	}
	loop(q){
		cin >> x;
		if(x==1){
			cin >> l >> c;
			l--;
			t=1;
			for(int j=0; j<18; j++){
				if(vec[j][0].empty()) break;
				if(l/t>=vec[j][0].size()) break;
				vec[j][s[l]-97].at(l/t)--;
				vec[j][c-97].at(l/t)++;
				t=t*2;
			}
			s[l]=c;
		}
		if(x==2){
			cin >> l >> r;
			l--;
			ans=0;
			t=1;
			for(int j=0; j<26; j++) arr[j]=0;
			for(int j=0; j<18; j++){
				t=t*2;
				if(l%t!=0){
					for(int k=0; k<26; k++){
						arr[k]=arr[k]+vec[j][k].at(l/(t/2));
					}
					l=l+t/2;
				}
				if(r%t!=0){
					for(int k=0; k<26; k++){
						arr[k]=arr[k]+vec[j][k].at(r/(t/2)-1);
					}
					r=r-t/2;
				}
				if(l>=r) break;
			}
			for(int j=0; j<26; j++){
				if(arr[j]>0) ans++;
			}
			cout << ans << endl;
		}
	}
	return 0;
}
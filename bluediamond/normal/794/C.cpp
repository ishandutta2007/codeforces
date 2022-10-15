#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	string sol;
	string sol_inv;
	string s,t;
	cin>>s>>t;
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());
	reverse(t.begin(),t.end());
	int n = s.length();
	deque<char> a,b;
	for(int i=0;i<(n+1)/2;i++)
	{
		a.push_back(s[i]);
	}
	for(int i=0;i<n/2;i++){
		b.push_back(t[i]);
	}
	for(int i=0;i<n;i++){
		if(i%2==0){
            if(!b.empty()&&a[0]>=b[0]){
				sol_inv+=a.back();
				a.pop_back();
            }
			else{
				sol+=a[0];
				a.pop_front();
			}
		}
        else{
			if(!a.empty()&&a[0]>=b[0]){
				sol_inv+=b.back();
				b.pop_back();
			}
			else{
                sol+=b[0];
				b.pop_front();
			}
		}
	}
	reverse(sol_inv.begin(),sol_inv.end());
	sol+=sol_inv;
	cout<<sol<<"\n";
    return 0;
}
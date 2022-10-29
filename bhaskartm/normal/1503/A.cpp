#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string st;
		cin>>st;
		string st1="";
		string st2="";
		int num=0;
		for(auto ch:st){
			if(ch=='1'){
				num++;
			}
		}
		bool che=1;
		if(num%2==1){
			cout<<"NO"<<endl;
			continue;
		}
		int ev=0;
		int cnt=0;
		for(int i=0; i<n; i++){
			if(st[i]=='1'){
				if(cnt<(num/2)){
					st1+="(";
					st2+="(";
				}
				else{
					st1+=")";
					st2+=")";
				}
				cnt++;
			}
			else{
				if(ev%2==0){
					st1+="(";
					st2+=")";
				}
				else{
					st1+=")";
					st2+="(";
				}
				ev++;
			}
			
		}
		int nums=0;
		for(int i=0; i<st1.size(); i++){
			if(st1[i]=='('){
				nums++;
			}
			else{
				nums--;
			}
			if(nums<0){
				che=0;
			}
		}
		nums=0;
		for(int i=0; i<st2.size(); i++){
			if(st2[i]=='('){
				nums++;
			}
			else{
				nums--;
			}
			if(nums<0){
				che=0;
			}
		}
		if(che){
			cout<<"YES"<<endl;
			cout<<st1<<endl<<st2<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define endl '\n'

int N=1000000007;



 main() {
	int t;
	cin>>t;
	int pot[1000005];
	int pot2[1000005];
	int pot3[1000005];
	pot[0]=1;
	pot2[0]=1;
	pot3[0]=1;
	for(int i=1; i<1000004; i++){
		pot[i]=(pot[i-1]*31)%N;
		pot2[i]=(pot2[i-1]*37)%N;
		pot3[i]=(pot3[i-1]*47)%N;
	}
	while(t--){
		string s;
		
		cin>>s;
		int n=s.size();
		int arr[s.size()];
		for(int i=0; i<s.size(); i++){
			arr[i]=(s[i]-'a'+1);
		}
		bool b=1;
		
		for(int i=0; i<n; i++){
			if(arr[i]!=arr[n-i-1]){
				b=0;
			}
		}
		if(b){
			
			cout<<s<<endl;
			continue;
		}
		int pointer=-1;
		for(int i=0; i<n; i++){
			if(arr[i]==arr[n-1-i]){
				pointer++;
			}
			else{
				break;
			}
		}
		
		int m=n-2*(pointer+1);
		int arr2[m];
		for(int i=pointer+1; i<n-pointer-1; i++){
			arr2[i-pointer-1]=arr[i];
		}
		int arr3[m];
		
		for(int i=m-1; i>=0; i--){
			arr3[i]=arr2[m-1-i];
		}
		int p1=31;
		int p2=37;
		int p3=47;
		int hf1=0;
		int hf2=0;
		int hf3=0;
		int hg1=0;
		int hg2=0;
		int hg3=0;
		int cnt1=0;
		for(int i=0; i<m; i++){
			hf1=(hf1+(arr2[i])*pot[i])%N;
			hf2=(hf2+(arr2[i])*pot2[i])%N;
			hf3=(hf3+(arr2[i])*pot3[i])%N;
			hg1=((hg1*p1)+(arr3[m-i-1]))%N;
			
			hg2=((hg2*p2)+(arr3[m-i-1]))%N;
			hg3=((hg3*p3)+(arr3[m-i-1]))%N;
			if(hf1==hg1 && hf2==hg2 && hf3==hg3){
				
				cnt1=max(cnt1, i+1);
			}
		}
		
		
		hf1=0;
		hf2=0;
		hg1=0;
		hg2=0;
		hf3=0;
		hg3=0;
		int cnt2=0;
		
		
		for(int i=0; i<m; i++){
			hg1=(hg1+(arr3[i])*pot[i])%N;
			hg2=(hg2+(arr3[i])*pot2[i])%N;
			hg3=(hg3+(arr3[i])*pot3[i])%N;
			hf1=((hf1*p1)+(arr2[m-i-1]))%N;
			hf2=((hf2*p2)+(arr2[m-i-1]))%N;
			hf3=((hf3*p3)+(arr2[m-i-1]))%N;
			if(hf1==hg1 && hf2==hg2 && hf3==hg3){
				cnt2=max(cnt2, i+1);
			}
		}
		
		if(cnt1>cnt2){
			for(int i=0; i<=pointer; i++){
				cout<<s[i];
			}
			for(int i=pointer+1; i<=pointer+cnt1; i++){
				cout<<s[i];
			}
			for(int i=s.size()-pointer-1; i<s.size(); i++){
				cout<<s[i];
			}
			cout<<endl;
			
		}
		else{
			for(int i=0; i<=pointer; i++){
				cout<<s[i];
			}
			for(int i=s.size()-pointer-1-cnt2; i<s.size()-pointer-1; i++){
				cout<<s[i];
			}
			for(int i=s.size()-pointer-1; i<s.size(); i++){
				cout<<s[i];
			}
			cout<<endl;
			
		}
	}
	return 0;
}
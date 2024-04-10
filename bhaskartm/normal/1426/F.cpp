#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

const int N=1e9+7;

int po[200005];
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	string st;
	cin>>st;
	po[0]=1;
	int ta=0;
	int tb=0;
	int tc=0;
	for(int i=0; i<n; i++){
		if(st[i]=='a'){
			ta++;
		}
		else if(st[i]=='b'){
			tb++;
		}
		else if(st[i]=='c'){
			tc++;
		}
	}
	for(int i=1; i<200005; i++){
		po[i]=(po[i-1]*3)%N;
	}
	int q=0;
	int ab=0;
	int a=0;
	int ans=0;
	int c1=0;
	for(int i=0; i<n; i++){
		if(st[i]=='a'){
			a++;
		}
		else if(st[i]=='b'){
			ab=(ab+a)%N;
		}
		else if(st[i]=='c'){
			c1=(c1+ab)%N;
		}
		else{
			q++;
		}
	}
	ans=(ans+po[q]*c1)%N;

	int val=((q)*(q-1)*(q-2))/6;
	val=val%N;
	if(q>=3){
		val=(val*po[q-3])%N;
	}
	ans=(ans+val)%N;
	
	a=0;
	ab=0;
	c1=0;
	for(int i=0; i<n; i++){
		if(st[i]=='a'){
			a++;
		}
		else if(st[i]=='b'){
			ab=(ab+a)%N;
		}
		else if(st[i]=='?'){
			c1=(c1+ab)%N;
		}
		else{
			
		}
	}
	if(q>=1){
		ans=(ans+po[q-1]*c1)%N;
	}
	
	int bc=0;
	int c=0;
	c1=0;
	for(int i=n-1; i>=0; i--){
		if(st[i]=='c'){
			c++;
		}
		else if(st[i]=='b'){
			bc=(bc+c)%N;
		}
		else if(st[i]=='?'){
			c1=(c1+bc)%N;
		}
	}
	
	if(q>=1){
		ans=(ans+c1*po[q-1])%N;
	}
	
	int ac=0;
	int aa=0;
	int cc=tc;
	c1=0;
	for(int i=0; i<n; i++){
		if(st[i]=='?'){
			c1=(c1+aa*cc)%N;
		}
		else if(st[i]=='a'){
			aa++;
		}
		else if(st[i]=='c'){
			cc--;
		}
	}
	
	if(q>=1){
		ans=(ans+po[q-1]*c1)%N;
	}
	
	c1=0;
	int qq=q;
	aa=0;
	for(int i=0; i<n; i++){
		if(st[i]=='?'){
			qq--;
			c1=(c1+aa*qq)%N;
		}
		else if(st[i]=='a'){
			aa++;
		}
	}
	if(q>=2){
		ans=(ans+po[q-2]*c1)%N;
	}
	cc=0;
	qq=q;
	c1=0;
	for(int i=n-1; i>=0; i--){
		if(st[i]=='c'){
			cc++;
		}
		else if(st[i]=='?'){
			qq--;
			c1=(c1+(qq*cc))%N;
		}
		
	}
	if(q>=2){
		ans=(ans+po[q-2]*c1)%N;
	}	
	c1=0;
	int q1=0;
	int q2=q;
	for(int i=0; i<n; i++){
		if(st[i]=='?'){
			q1++;
			q2--;
		}
		else if(st[i]=='b'){
			 c1=(c1+(q1*q2))%N;
		}
	}
	if(q>=2){
		ans=(ans+c1*po[q-2])%N;
	}
	cout<<ans<<endl;
	return 0;
}
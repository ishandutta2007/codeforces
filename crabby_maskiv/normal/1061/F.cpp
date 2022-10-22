#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1.5e3+5;
int n,m;
vector<int> v;
inline int Rand(){
	return rand()%n+1;
}
int main(){
	srand((unsigned)time(NULL));
	int i,j;
	cin>>n>>m;
	int s=1,w=m,d=0;
	while(s<n){
		s+=w;
		w*=m;
		d++;
	}
	int x,y;
	for(i=1;i<=40;i++){
		x=Rand();y=Rand();
		v.clear();
		for(j=1;j<=n;j++){
			cout<<"? "<<x<<" "<<j<<" "<<y<<endl;
			fflush(stdout);
			string str;cin>>str;
			if(str=="Yes") v.push_back(j);
		}
		if(v.size()==2*d+1) break;
	}
	for(i=0;i<2*d+1;i++){
		int cnt=0;
		for(j=0;j<2*d+1;j++){
			cout<<"? "<<x<<" "<<v[j]<<" "<<v[i]<<endl;
			fflush(stdout);
			string str;cin>>str;
			if(str=="Yes") cnt++;
		}
		if(cnt==d+1){
			cout<<"! "<<v[i]<<endl;
			fflush(stdout);
			return 0;
		}
	}
	return 0;
}
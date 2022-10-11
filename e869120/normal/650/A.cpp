#include<bits/stdc++.h>
using namespace std;
vector<long long>X,Y,X_,Y_;
map<pair<long long,long long>,long long>M;
long long x[200000],y[200000],rx[200000],ry[200000],n;
long long a[300000],b[300000],cnt,cnt2;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];rx[i]=x[i];ry[i]=y[i];
		X.push_back(x[i]);
		Y.push_back(y[i]);
		M[make_pair(x[i],y[i])]++;
	}
	sort(X.begin(),X.end());sort(Y.begin(),Y.end());X_.push_back(X[0]);Y_.push_back(Y[0]);
	for(int i=1;i<X.size();i++){if(X[i-1]!=X[i])X_.push_back(X[i]);}
	for(int i=1;i<Y.size();i++){if(Y[i-1]!=Y[i])Y_.push_back(Y[i]);}
	for(int i=0;i<n;i++){
		int pos1=lower_bound(X_.begin(),X_.end(),x[i])-X_.begin();
		int pos2=lower_bound(Y_.begin(),Y_.end(),y[i])-Y_.begin();
		x[i]=pos1;y[i]=pos2;a[x[i]]++;b[y[i]]++;
	}
	for(int i=0;i<300000;i++){
		cnt+=1LL*a[i]*(a[i]-1LL)/2LL;cnt+=1LL*b[i]*(b[i]-1LL)/2LL;
	}
	for(int i=0;i<n;i++){
		cnt2+=M[make_pair(rx[i],ry[i])]-1;
	}
	cout<<cnt-(cnt2/2)<<endl;
	return 0;
}
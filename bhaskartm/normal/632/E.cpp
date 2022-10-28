#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
const double PI=acos(-1);
void fft(vector<cd> & a, bool invert){
	int n=a.size();
	for(int i=1, j=0; i<n; i++){
		int bit=n>>1;
		for(; j&bit; bit>>=1)
			j ^=bit;
		j^=bit;
		if(i<j)
			swap(a[i], a[j]);
	}
	for(int len=2; len<=n; len <<=1){
		double ang=2*PI/len*(invert ? -1 : 1);
		cd wlen(cos(ang), sin(ang));
		for(int i=0; i<n; i+=len){
			cd w(1);
			for(int j=0; j<len/2; j++){
				cd u=a[i+j], v=a[i+j+len/2]*w;
				a[i+j]=u+v;
				a[i+j+len/2]=u-v;
				w*=wlen;
			}
		}
	}
	if(invert){
		for(cd & x : a)
			x /= n;
	}
}
 
vector<int> multiply(vector<int>const& a, vector<int>const& b){
	vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int n=1;
	while(n<a.size()+b.size())
		n <<= 1;
	fa.resize(n);
	fb.resize(n);
	fft(fa, false);
	fft(fb, false);
	for(int i=0; i<n; i++)
		fa[i] *= fb[i];
	fft(fa, true);
	vector<int>result(n);
	for(int i=0; i<n; i++)
		result[i]=round(fa[i].real());
	return result;
}
 
vector<int> binom(vector<int>const& v, int k){
	vector<int>result;
	for(int i=0; i<v.size(); i++){
		result.push_back(v[i]);
	}
	if(k==1){
		return result;
	}
	if(k%2==0){
		auto u=multiply(result, result);
		while(u.back()==0){
			u.pop_back();
		}
		for(int i=0; i<u.size(); i++){
			if(u[i]>0){
				u[i]=1;
			}
		}
		return binom(u, k/2);
	}
	else{
		
		auto val=binom(result, k-1);
		while(val.back()==0){
			val.pop_back();
		}
		for(int i=0; i<val.size(); i++){
			if(val[i]>0){
				val[i]=1;
			}
		}
		return multiply(result, val);
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin>>n>>k;
	int arr[n];
	int maxi=0;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		maxi=max(maxi, arr[i]);
	}
	vector<int>x;
	x.resize(maxi+1);
	for(int i=0; i<=maxi; i++){
		x[i]=0;
	}
	for(int i=0; i<n; i++){
		x[arr[i]]=1;
	}
	
	
	
	auto ans=binom(x, k);
	
	for(int i=0; i<ans.size(); i++){
		if(ans[i]!=0){
			cout<<i<<" ";
		}
	}
	return 0;
}
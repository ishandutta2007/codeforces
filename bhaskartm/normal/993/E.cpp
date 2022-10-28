#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define s second
#define f first
#define int long long int
using cd = complex<double>;
const double PI=acos(-1);
bool che[125001][6][6];
bool vis[125001][6];
int num=0;
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


main() {
	int n, x;
	cin>>n>>x;
	vector<int>v;
	for(int i=0; i<n; i++){
		int y;
		cin>>y;
		if(y<x){
			v.pb(1);
		}
		else{
			v.pb(0);
		}
	}
	vector<int>pre;
	pre.pb(0);
	for(int i=0; i<n; i++){
		pre.pb(v[i]+pre[i]);
	}
	int maxi=pre.back();
	vector<int>f;
	f.resize(maxi+1);
	for(int i=0; i<=maxi; i++){
		f[i]=0;
	}
	for(int i=0; i<pre.size(); i++){
		f[pre[i]]++;
	}
	vector<int>fr;
	for(int i=0; i<f.size(); i++){
		fr.pb(f[i]);
	}
	
	reverse(fr.begin(), fr.end());
	vector<int>mul=multiply(f, fr);
	vector<pair<int, int>>r;
	
	for(int i=0; i<n; i++){
		if(r.size()==0){
			if(v[i]==0){
				r.pb({1, 0});
			}
			else{
				r.pb({1, 1});
			}
			continue;
		}
		int val=r.back().s;
		int cnt=r.back().f;
		if(v[i]==val){
			r.pop_back();
			r.pb({cnt+1, val});
		}
		else{
			r.pb({1, 1-val});
		}
	}
	int ans=0;
	
	for(auto u:r){
		if(u.s==0){
			ans+=((u.f)*(u.f+1))/2;
		}
	}
	for(int i=0; i<=n; i++){
		mul.pb(0);
	}
	cout<<ans<<" ";
	for(int i=1; i<=n; i++){
		cout<<mul[maxi+i]<<" ";
	}
	
	return 0;
}
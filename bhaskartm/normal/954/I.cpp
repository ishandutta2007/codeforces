#include <bits/stdc++.h>
using namespace std;

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

void dfs(int v, int ind){
	vis[ind][v]=1;
	num++;
	for(int i=0; i<6; i++){
		if(vis[ind][i]==0 && che[ind][v][i]){
			dfs(i, ind);
		}
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	string t;
	cin>>s>>t;
	for(int i=0; i<6; i++){
		for(int j=0; j<6; j++){
			if(i==j){
				continue;
			}
			vector<int>x;
			vector<int>y;
			for(int k=0; k<s.size(); k++){
				if(int(s[k]-'a')==i){
					x.push_back(1);
				}
				else{
					x.push_back(0);
				}
			}
			for(int k=0; k<t.size(); k++){
				if(int(t[k]-'a')==j){
					y.push_back(1);
				}
				else{
					y.push_back(0);
				}
			}
			reverse(x.begin(), x.end());
			auto v=multiply(x, y);
			for(int k=s.size()-t.size(); k>=0; k--){
				if(v[t.size()-1+(s.size()-t.size()-k)]!=0){
					che[k][i][j]=1;
					che[k][j][i]=1;
				}
			}
		}
	}
	for(int i=0; i<=s.size()-t.size(); i++){
		int ans=0;
		for(int j=0; j<6; j++){
			if(vis[i][j]==0){
				num=0;
				dfs(j, i);
				ans+=num-1;
			}
		}
		cout<<ans<<" ";
	}
	
	return 0;
}
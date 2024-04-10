#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
//#define int long long
using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

inline void query1(vector<int> &a)
{
	cout<<'?'<<' '<<(int)a.size()<<' ';
	for(int i=0;i<(int)a.size();i++) cout<<a[i]<<' ';
	cout<<'\n';fflush(stdout);
}

inline void query2(vector<int> &a,vector<int> &b)
{
	cout<<'?'<<' '<<(int)a.size()+(int)b.size()<<' ';
	for(int i=0;i<(int)a.size();i++) cout<<a[i]<<' ';
	for(int i=0;i<(int)b.size();i++) cout<<b[i]<<' ';
	cout<<'\n';fflush(stdout);
}

inline void ask(int &a)
{
	string s;cin>>s;
	if(s=="NO") a=0;
	else a=1;
}

signed main()
{
	srand(time(0));
	ios::sync_with_stdio(false);
	int n;cin>>n;
	vector<int> v;
	for(int i=1;i<=n;i++) v.push_back(i);
	while((int)v.size()>=3){
		vector<int> v1,v2,v3,v4;
		random_shuffle(v.begin(),v.end());
		if((int)v.size()==3){
			int len1=(int)v.size()/3,len2=((int)v.size()-len1)/2,len3=(int)v.size()-len1-len2;
			for(int i=0;i<len1;i++) v1.push_back(v[i]);
			for(int i=0;i<len2;i++) v2.push_back(v[len1+i]);
			for(int i=0;i<len3;i++) v3.push_back(v[len1+len2+i]);
			query2(v1,v2);int x;ask(x);
			query1(v1);int y;ask(y);
			if(x==0&&y==0){
				v.clear();
				for(int i=0;i<(int)v2.size();i++) v.push_back(v2[i]);
				for(int i=0;i<(int)v3.size();i++) v.push_back(v3[i]);
			}
			else if(x==0&&y==1){
				v.clear();
				for(int i=0;i<(int)v1.size();i++) v.push_back(v1[i]);
				for(int i=0;i<(int)v3.size();i++) v.push_back(v3[i]);
			}
			else if(x==1&&y==0){
				query2(v2,v3);int z;ask(z);
				if(z==1){
					v.clear();
					for(int i=0;i<(int)v2.size();i++) v.push_back(v2[i]);
					for(int i=0;i<(int)v3.size();i++) v.push_back(v3[i]);
				}
				else{
					query2(v1,v3);int w;ask(w);
					if(w==0){
						v.clear();
						for(int i=0;i<(int)v1.size();i++) v.push_back(v1[i]);
						for(int i=0;i<(int)v2.size();i++) v.push_back(v2[i]);
					}
					else{
						v.clear();
						for(int i=0;i<(int)v1.size();i++) v.push_back(v1[i]);
						for(int i=0;i<(int)v3.size();i++) v.push_back(v3[i]);
					}
				}
			}
			else{
				v.clear();
				for(int i=0;i<(int)v1.size();i++) v.push_back(v1[i]);
				for(int i=0;i<(int)v2.size();i++) v.push_back(v2[i]);
			}
		}
		else{
			int len1=((int)v.size())/4,len2=((int)v.size()-len1)/3;
			int len3=((int)v.size()-len1-len2)/2,len4=((int)v.size()-len1-len2-len3);
			for(int i=0;i<len1;i++) v1.push_back(v[i]);
			for(int i=0;i<len2;i++) v2.push_back(v[len1+i]);
			for(int i=0;i<len3;i++) v3.push_back(v[len1+len2+i]);
			for(int i=0;i<len4;i++) v4.push_back(v[len1+len2+len3+i]);
			query2(v1,v2);int x;ask(x);
			query2(v1,v3);int y;ask(y);
			if(x==0&&y==0){
				query2(v2,v4);int z;ask(z);
				if(z==1){
					v.clear();
					for(int i=0;i<(int)v2.size();i++) v.push_back(v2[i]);
					for(int i=0;i<(int)v4.size();i++) v.push_back(v4[i]);
				}
				else{
					query2(v2,v3);int w;ask(w);
					if(w==0){
						v.clear();
						for(int i=0;i<(int)v3.size();i++) v.push_back(v3[i]);
						for(int i=0;i<(int)v4.size();i++) v.push_back(v4[i]);
					}
					else{
						v.clear();
						for(int i=0;i<(int)v2.size();i++) v.push_back(v2[i]);
						for(int i=0;i<(int)v3.size();i++) v.push_back(v3[i]);
					}
				}
			}
			else if(x==0&&y==1){
				query2(v1,v3);int z;ask(z);
				if(z==1){
					v.clear();
					for(int i=0;i<(int)v1.size();i++) v.push_back(v1[i]);
					for(int i=0;i<(int)v3.size();i++) v.push_back(v3[i]);
				}
				else{
					query2(v1,v4);int w;ask(w);
					if(w==0){
						v.clear();
						for(int i=0;i<(int)v3.size();i++) v.push_back(v3[i]);
						for(int i=0;i<(int)v4.size();i++) v.push_back(v4[i]);
					}
					else{
						v.clear();
						for(int i=0;i<(int)v1.size();i++) v.push_back(v1[i]);
						for(int i=0;i<(int)v4.size();i++) v.push_back(v4[i]);
					}
				}
			}
			else if(x==1&&y==0){
				query2(v2,v4);int z;ask(z);
				if(z==1){
					v.clear();
					for(int i=0;i<(int)v2.size();i++) v.push_back(v2[i]);
					for(int i=0;i<(int)v4.size();i++) v.push_back(v4[i]);
				}
				else{
					query2(v1,v2);int w;ask(w);
					if(w==0){
						v.clear();
						for(int i=0;i<(int)v1.size();i++) v.push_back(v1[i]);
						for(int i=0;i<(int)v4.size();i++) v.push_back(v4[i]);
					}
					else{
						v.clear();
						for(int i=0;i<(int)v1.size();i++) v.push_back(v1[i]);
						for(int i=0;i<(int)v2.size();i++) v.push_back(v2[i]);
					}
				}
			}
			else{
				query2(v1,v3);int z;ask(z);
				if(z==1){
					v.clear();
					for(int i=0;i<(int)v1.size();i++) v.push_back(v1[i]);
					for(int i=0;i<(int)v3.size();i++) v.push_back(v3[i]);
				}
				else{
					query2(v1,v2);int w;ask(w);
					if(w==0){
						v.clear();
						for(int i=0;i<(int)v2.size();i++) v.push_back(v2[i]);
						for(int i=0;i<(int)v3.size();i++) v.push_back(v3[i]);
					}
					else{
						v.clear();
						for(int i=0;i<(int)v1.size();i++) v.push_back(v1[i]);
						for(int i=0;i<(int)v2.size();i++) v.push_back(v2[i]);
					}
				}
			}
		}
	}
	for(int i=0;i<(int)v.size();i++){
		cout<<'!'<<' '<<v[i]<<'\n';fflush(stdout);
		string s;cin>>s;
		if(s==":)") break;
	}
	return 0;
}
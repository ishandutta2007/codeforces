#include<bits/stdc++.h>
using namespace std;
int n;
string s;
struct Data {
    int cnt;
    char last;
    string s;
    bool operator<(const Data &o) const {
    	return cnt != o.cnt ? cnt < o.cnt : last < o.last;
    }
};
void solve() {
   	cin>>n;
    vector<Data>v,b,x,y;
    for(int i=0;i<n;i++){
		cin>>s;
		int cnt = 0;
		char last = 0;
		for(int j=0;j<s.size();j++){
		    switch(s[j]){
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
			    cnt++;
			    last=s[j];
			    break;
			}
		}
		v.push_back((Data){cnt,last,s});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
		if(i+1<(int)v.size()&&v[i].cnt==v[i+1].cnt&&v[i].last==v[i+1].last){
	    	b.push_back(v[i]);
	    	b.push_back(v[i+1]);
	    	i++;
		}else
			x.push_back(v[i]);
    }
    for(int i=0;i<x.size();i++){
		if (i+1<x.size()&&x[i].cnt==x[i+1].cnt) {
		    y.push_back(x[i]);
		    y.push_back(x[i+1]);
		    i++;
		}
    }
    vector<string>ans;
    while(true){
		if(!b.empty() && !y.empty()) {
		    for(int i=0;i<2;i++){
				ans.push_back(y.back().s);y.pop_back();
				ans.push_back(b.back().s);b.pop_back();
		    }
		}else if(b.size()>=4){
	   		string tmp1=b.back().s;b.pop_back();
	    	string tmp2=b.back().s;b.pop_back();
	    	ans.push_back(b.back().s); b.pop_back();
	    	ans.push_back(tmp1);
	    	ans.push_back(b.back().s); b.pop_back();
	    	ans.push_back(tmp2);
		}else break;
    }
    cout<<ans.size()/4<<endl;
    for(int i=0;i<ans.size()/2;i++)
		cout<<ans[i*2]<<' '<<ans[i*2+1]<<endl;
}
int main(){
    solve();
}
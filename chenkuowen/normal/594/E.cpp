#include<bits/stdc++.h>
using namespace std;
const int N=5+2e7;
char s[N];
vector<string> duval(string s){
	vector<string> ret;
	int n=s.length();
	int i=-1,j=0,k=1;
	while(k<=n){
		if(k==n||s[k]<s[j]){
			while(i<j) ret.push_back(s.substr(i+1,k-j)),i+=k-j;
			j=i+1,k=i+2;
		}else if(s[j]==s[k]) ++j,++k;
		else j=i+1,++k;
	}
	return ret;
}
void ex_kmp(string a,string b,vector<int>& match,vector<int>& nxt){
	int n=a.length(),m=b.length();
	for(int i=0,p0=-1;i<n;++i){
		int j=i<=1?0:max(p0+match[p0]-i,0); 
		if(i>1&&nxt[i-p0]<j) match[i]=nxt[i-p0];
		else{
			while(i+j<n&&j<m&&a[i+j]==b[j]) ++j;
			match[p0=i]=j;
		}
	}
}
void init(string& s,int& k){
	vector<string> a=duval(s);
	string last;
	for(int i=(int)a.size()-1;i>=1;--i){
		if(k<=2) break;
		if(a[i]==a[i-1]||(a[i].size()==1&&a[i-1].size()==1));
		else --k;
		cout<<a[i];
		a.pop_back();
	}
	s="";
	for(auto x:a) s.append(x);
}
string solve00(string s){ //s
	return s;
}
string solve10(string s){ //s
	string rs=s; reverse(rs.begin(),rs.end());
	vector<string> a=duval(s),b;
	string last="";
	for(auto x:a){
		if(x==last) b[(int)b.size()-1].append(x);
		else b.push_back(x);
	}
	int j=(int)b.size()-1;
	string sb=b[j];
	for(int i=(int)b.size()-2;i>=0;--i){
		string sb1=b[i]+sb;
		if(sb1>sb+rs.substr(sb.size(),sb1.size()-sb.size()))
			break;
		else{
			j=i;
			sb=sb1;
		}
	}
	return sb+rs.substr(sb.size(),rs.size()-sb.size());
}
string solve01(string s){//s
	string rs=s; reverse(rs.begin(),rs.end());
	swap(s,rs);
	vector<int> nxt,match;
	nxt=match=vector<int>(s.length()+5,0);
	ex_kmp(rs,rs,nxt,nxt);
	ex_kmp(s,rs,match,nxt);
	int j=s.length()-1;
	for(int i=(int)s.length()-2;i>=0;--i){
//		cout<<s.substr(0,j+1)+rs.substr(0,(int)s.length()-j-1)<<endl;
//		cout<<s.substr(0,i+1)+rs.substr(0,(int)s.length()-i-1)<<endl;
		int len=min(match[i+1],j-i);
//		if(len>0){
//			cout<<"<"<<s[i+1]<<">"<<endl;
//			cout<<"<"<<rs[0]<<">"<<endl;
//			assert(s[i+1+len-1]==rs[len-1]);
//		}
//		cout<<"["<<i<<" "<<j<<" "<<len<<"]"<<endl;
		if(len<j-i){
			if(s[i+1+len]>rs[len]) j=i;
//			cerr<<endl;
			continue;
		}
		len=nxt[len-1];
		if(j-i+len<s.length()&&rs[len]>rs[j-i+len]) j=i;
//		cout<<endl;
	}
	return s.substr(0,j+1)+rs.substr(0,(int)s.length()-j-1);
}
string solve11(string s){ //
	vector<string> a=duval(s+s);
	int len=0;
	for(int i=0;i<a.size();++i){
		if(len<s.length()&&len+a[i].length()>=s.length())
			return s.substr(len,s.length()-len)+s.substr(0,len);
		len+=a[i].length();
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	string s; cin>>s;
	int k; cin>>k;
	if(k==1){
		string rs=s; reverse(rs.begin(),rs.end());
		cout<<min(s,rs)<<endl;
		return 0;
	}
	reverse(s.begin(),s.end());
	init(s,k);
	if(!s.empty())
		cout<<min({solve00(s),solve10(s),solve01(s),solve11(s)});
	return 0;
}
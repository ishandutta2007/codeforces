#include<bits/stdc++.h>
using namespace std;
typedef pair<vector<string>,int> mat;
void output(mat s){
	cout<<s.first.size()<<' '<<s.first[0].size()<<endl;
	for(int i=0;i<s.first.size();i++)
		cout<<s.first[i]<<endl;
}
mat btf(mat s){
	mat ret;
	for(int i=0;i<s.first.size();i++)
		s.first[i]="+ "+s.first[i]+" +";
	string t;
	for(int i=0;i<s.first[0].size();i++)
		t+='-';
	t[0]='+';t[s.first[0].size()-1]='+';
	ret.first.push_back(t);
	for(int i=0;i<s.first.size();i++)
		ret.first.push_back(s.first[i]);
	ret.first.push_back(t);
	ret.second=s.second+1;
	return ret;
}
mat bg(string s){
	mat ret;ret.second=0;
	ret.first.push_back(s);
	return ret;
}
mat alland(vector<mat>s){
	if(s.size()==1)return s[0];
	int l=0,r=0;
	for(int i=0;i<s.size();i++){
		int L=s[i].second,R=s[i].first.size()-L-1;
		l=max(L,l);r=max(R,r); 
	}
	mat ret;
	for(int i=0;i<l+r+1;i++)ret.first.push_back(""); 
	for(int i=0;i<s.size();i++){
		if(i){
			for(int j=0;j<l;j++)ret.first[j]+="  ";
			ret.first[l]+="->";
			for(int j=l+1;j<l+r+1;j++)ret.first[j]+="  ";
		}
		string t;
		int L=l-s[i].second,R=r-s[i].first.size()+s[i].second+1;
		for(int j=0;j<s[i].first[0].size();j++)t+=' ';
		for(int j=0;j<L;j++)ret.first[j]+=t;
		for(int j=0;j<s[i].first.size();j++)
			ret.first[j+L]+=(s[i].first[j]);
		for(int j=0;j<R;j++)ret.first[l+r-j]+=t;
	}
	ret.second=l;
	return ret;
}
mat allor(vector<mat>s){
	if(s.size()==1)return s[0];
	mat ret;ret.second=s[0].second;
	int m=0,n=-1;
	for(int i=0;i<s.size();i++){
		m=max(m,int(s[i].first[0].size())+6);
		n+=s[i].first.size();n++;
	}
	for(int i=0;i<n;i++){
		ret.first.push_back("");
		for(int j=0;j<m;j++)
			ret.first[i]+=' '; 
	}
	for(int i=s[0].second;i<n-s.back().first.size()+s.back().second+1;i++)ret.first[i][0]='|';
	for(int i=s[0].second;i<n-s.back().first.size()+s.back().second+1;i++)ret.first[i][m-1]='|';
	int sum=0;
	for(int i=0;i<s.size();i++){
		ret.first[sum+s[i].second][0]='+';
		ret.first[sum+s[i].second][m-1]='+';
		for(int j=1;j<m-1;j++)
			ret.first[sum+s[i].second][j]='-';
		ret.first[sum+s[i].second][2]='>';
		ret.first[sum+s[i].second][m-2]='>';
		for(int j=0;j<s[i].first.size();j++)
			for(int k=0;k<s[i].first[0].size();k++)
				ret.first[sum+j][k+3]=s[i].first[j][k];
		sum+=s[i].first.size()+1;
	}
	return ret;
}
mat pls(mat s){
	mat ret;
	for(int i=0;i<s.first.size()+2;i++){
		ret.first.push_back("");
		for(int j=0;j<s.first[0].size()+6;j++)
			ret.first[i]+=' ';
	}
	int n=s.first.size(),m=s.first[0].size(),l=s.second;
	for(int i=l;i<n+2;i++)
		ret.first[i][0]='|';
	for(int i=l;i<n+2;i++)
		ret.first[i][m+5]='|';
	for(int i=0;i<m+6;i++)
		ret.first[l][i]='-';
	for(int i=0;i<m+6;i++)
		ret.first[n+1][i]='-';
	ret.first[l][0]='+';ret.first[l][2]='>';ret.first[l][m+4]='>';ret.first[l][m+5]='+';
	ret.first[n+1][0]='+';ret.first[n+1][1]='<';ret.first[n+1][m+5]='+';
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			ret.first[i][j+3]=s.first[i][j];
	ret.second=s.second;
	return ret;
}
mat ask(mat s){
	mat ret;
	for(int i=0;i<s.first.size()+2;i++){
		ret.first.push_back("");
		for(int j=0;j<s.first[0].size()+6;j++)
			ret.first[i]+=' ';
	}
	int n=s.first.size(),m=s.first[0].size(),l=s.second;
	for(int i=0;i<l+3;i++)ret.first[i][0]='|';
	for(int i=0;i<l+3;i++)ret.first[i][m+5]='|';
	for(int i=0;i<m+6;i++)ret.first[0][i]='-';
	for(int i=0;i<m+6;i++)ret.first[l+2][i]='-';
	ret.first[0][0]='+';ret.first[0][m+5]='+';ret.first[l+2][0]='+';ret.first[l+2][m+5]='+'; 
	ret.first[0][m+4]='>';ret.first[l+2][2]='>';ret.first[l+2][m+4]='>';
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			ret.first[i+2][j+3]=s.first[i][j];
	mat RET;RET.second=1;string t="";for(int i=0;i<m+6;i++)t+=' ';RET.first.push_back(t);
	for(int i=0;i<n+2;i++)RET.first.push_back(ret.first[i]);
	return RET;
}
mat mul(mat s){
	mat ret;
	for(int i=0;i<s.first.size()+4;i++){
		ret.first.push_back("");
		for(int j=0;j<s.first[0].size()+6;j++)
			ret.first[i]+=' ';
	}
	int n=s.first.size(),m=s.first[0].size(),l=s.second;
	for(int i=0;i<m+6;i++)ret.first[0][i]='-';
	for(int i=0;i<m+6;i++)ret.first[l+2][i]='-';
	for(int i=0;i<m+6;i++)ret.first[n+3][i]='-';
	for(int i=0;i<n+3;i++)ret.first[i][0]='|';
	for(int i=0;i<n+3;i++)ret.first[i][m+5]='|';
	ret.first[0][0]='+';ret.first[0][m+5]='+';ret.first[l+2][0]='+';ret.first[l+2][m+5]='+';ret.first[n+3][0]='+';ret.first[n+3][m+5]='+';
	ret.first[0][m+4]='>';ret.first[l+2][2]='>';ret.first[l+2][m+4]='>';ret.first[n+3][1]='<'; 
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			ret.first[i+2][j+3]=s.first[i][j];
	mat RET;RET.second=1;string t="";for(int i=0;i<m+6;i++)t+=' ';RET.first.push_back(t);
	for(int i=0;i<n+4;i++)RET.first.push_back(ret.first[i]);
	return RET;
}
void OUT(mat s){
	vector<mat>ret;
	ret.push_back(bg("S"));
	ret.push_back(s);
	ret.push_back(bg("F"));
	output(alland(ret));
}
string s;
mat dfs(int l,int r){
	vector<mat>nw,NW;
	for(int i=l;i<=r;i++){
		if(s[i]=='|'){
			nw.push_back(alland(NW));
			NW.clear();continue; 
		}
		if(s[i]=='('){
			int nw=0,j=i;
			for(;;j++){
				if(s[j]=='(')
					nw++;
				if(s[j]==')')
					nw--;
				if(nw==0)break;
			}
			mat tmp=dfs(i+1,j-1);j++;
			for(;j<=r;j++){
				if(s[j]=='*'){tmp=mul(tmp);continue;}
				if(s[j]=='+'){tmp=pls(tmp);continue;}
				if(s[j]=='?'){tmp=ask(tmp);continue;}
				break;
			}
			i=j;if(j<=r)i--;
			NW.push_back(tmp);
			continue;
		}int j=i;
		for(;j<=r;j++)
			if(!isalpha(s[j]))
				break;
		if(j<=r&&(s[j]=='*'||s[j]=='+'||s[j]=='?')){
			string tmp;
			for(int k=i;k<j-1;k++)tmp+=s[k];
			if(tmp.size())NW.push_back(btf(bg(tmp)));
			string tttt;tttt+=s[j-1];
			mat TMP=btf(bg(tttt));
			for(;j<=r;j++){
				if(s[j]=='*'){TMP=mul(TMP);continue;}
				if(s[j]=='+'){TMP=pls(TMP);continue;}
				if(s[j]=='?'){TMP=ask(TMP);continue;}
				break;
			}i=j;if(j<=r)i--;
			NW.push_back(TMP);
			continue;
		}string tmp;
		for(int k=i;k<j;k++)tmp+=s[k];
		if(tmp.size())NW.push_back(btf(bg(tmp)));
		i=j;if(j<=r)i--;
	}nw.push_back(alland(NW));
	return allor(nw);
}
int main(){
	cin>>s;
	OUT(dfs(0,s.size()-1));
}
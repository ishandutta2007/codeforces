#include<bits/stdc++.h>
using namespace std;
struct check_macro{
	bool canuse=1;
	bool c[2][3]={{1,1,1},{1,1,1}};
};
map<string,check_macro>mp;
map<string,bool>vis;
check_macro retry(string s){
	check_macro can;
	for(int i=0;i<s.size();i++){
		if(s[i]=='('){
			string sub="";
			++i;
			int z=1;
			for(;i<s.size()&&z;i++){
				sub+=s[i];
				if(s[i]==')')z--;
				if(s[i]=='(')z++;
			}
			can.canuse&=retry(sub).canuse;
			//continue;
		}
		if(isalpha(s[i])){
			string sub="";
			for(;i<s.size()&&isalpha(s[i]);i++)sub+=s[i];
			if(vis[sub]){
				can.canuse&=mp[sub].canuse;
				for(int ii=0;ii<2;ii++)for(int jj=0;jj<3;jj++)can.c[ii][jj]&=mp[sub].c[ii][jj];
				for(int j=i;j<s.size()&&s[j]!=')';j++)
					if(!isalpha(s[j])&&!isdigit(s[j])&&s[j]!=' ')
					{
						if(s[j]=='/'&&!mp[sub].c[1][2])
							can.canuse=0;
						if(s[j]=='-'&&!mp[sub].c[1][0])
							can.canuse=0;
						if(s[j]=='*'&&!mp[sub].c[1][1])
							can.canuse=0;
						break;
					}
				for(int j=i-1;j>=0&&s[j]!='(';j--)
					if(!isalpha(s[j])&&!isdigit(s[j])&&s[j]!=' ')
					{
						if(s[j]=='/'&&!mp[sub].c[0][2])
							can.canuse=0;
						if(s[j]=='-'&&!mp[sub].c[0][0])
							can.canuse=0;
						if(s[j]=='*'&&!mp[sub].c[0][1])
							can.canuse=0;
						break;
					}
			}
		}
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(')
		{
			while(s[i]!=')')
				i++;
			//i++;
		}
		if(isalpha(s[i])||s[i]==' '||s[i]==')')continue;
		if(s[i]=='+'||s[i]=='-')
			for(int i=0;i<2;i++)
				for(int j=1;j<3;j++)
					can.c[i][j]=0;
		if(s[i]=='-'||s[i]=='+')can.c[0][0]=0;
		if(s[i]=='/')can.c[0][2]=0;
		if(s[i]=='*')can.c[0][2]=0;
	}
	//cout<<s<<endl;
	if(s[0]=='('){
		//cout<<s<<endl;
		int z=1,i=0;
		for(i=1;i<s.size();i++)
		{
			if(s[i]==')')z--;
			if(s[i]=='(')z++;
			if(!z)break;
		}
		if(i==s.size()-1){for(i=0;i<2;i++)for(int j=0;j<3;j++)can.c[i][j]=1;}
	} 
	return can;
}
int main(){
	int n;
	cin>>n;
	string s;
	getline(cin,s);
	for(int i=0;i<=n;i++){
		getline(cin,s);
		if(i==n)s="# define Cate "+s;
		int j=0;
		while(s[j]!='n')j++;
		j++;
		while(s[j]==' ')j++;
		while(s[j]!=' ')j++;
		while(s[j]==' ')j++;
		while(s.size()&&s[s.size()-1]==' ')s=s.substr(0,s.size()-1);
		string name="";
		while(s[j]!=' ')name+=s[j],j++;
		while(s[j]==' ')j++;
		s=s.substr(j);
		mp[name]=retry(s);
		//cout<<name<<endl;
		vis[name]=1;
		/*cout<<mp[name].canuse<<endl;
		for(int i=0;i<2;i++){
			for(int j=0;j<3;j++)
				cout<<mp[name].c[i][j]<<' ';
			cout<<endl;
		}*/
	}
	if(mp["Cate"].canuse==1)
		cout<<"OK";
	else
		cout<<"Suspicious";
}
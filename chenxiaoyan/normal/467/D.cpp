#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned int
string ess[100001];
vector<string> str(1);
int by[100001],R[100001];
vector<int> canrep[100001];
struct Map{
	map<ull,int> a;
	int &operator[](string &s){
		ull res=0;
		for(int i=0;i<s.size();i++)
			res=(res<<7)+(res<<1)+res+s[i]-'a'+1;
		return a[res];
	}
}id;
struct cmp{
	bool operator()(int a,int b){
		if(R[a]!=R[b])return R[a]>R[b];
		return str[a].size()>str[b].size();
	}
};
void dfs(int x){
	for(int i=0;i<canrep[x].size();i++)
		if(!by[canrep[x][i]])by[canrep[x][i]]=by[x],dfs(canrep[x][i]);
}
signed main(){
//	freopen("C:\\Users\\chenx\\Desktop\\txt.txt","r",stdin);
	int len,n,i,j,totR=0,totlen=0;cin>>len;
	for(i=1;i<=len;i++){
		cin>>ess[i];
		for(j=0;j<ess[i].size();j++)ess[i][j]=tolower(ess[i][j]);
	}
	cin>>n;
	while(n--){
		string a,b;cin>>a>>b;
		int r=0;
		for(i=0;i<a.size();i++)a[i]=tolower(a[i]),r+=a[i]=='r';
		if(!id[a])id[a]=str.size(),str.push_back(a);
		R[id[a]]=r;
		r=0;
		for(i=0;i<b.size();i++)b[i]=tolower(b[i]),r+=b[i]=='r';
		if(!id[b])id[b]=str.size(),str.push_back(b);
		R[id[b]]=r;
		canrep[id[b]].push_back(id[a]);
	}
//	for(i=1;i<str.size();i++){
//		printf("%s,id=%d,R=%d,canrep:",str[i].c_str(),id[str[i]],R[i]);
//		for(j=0;j<canrep[i].size();j++)cout<<canrep[i][j]<<"("<<str[canrep[i][j]]<<") ";
//		puts("");
//	}
	priority_queue<int,vector<int>,cmp> q;
	for(i=1;i<str.size();i++)q.push(i);
	while(q.size()){
		if(!by[q.top()])by[q.top()]=q.top(),dfs(q.top())
//		,cout<<"!!!!!"
		;
//		cout<<q.top()<<"("<<str[q.top()]<<")\n";
		q.pop();
	}
//	for(i=1;i<str.size();i++)
//		printf("%d(%s) by:%d(%s)\n",i,str[i].c_str(),by[i],str[by[i]].c_str());
	for(i=1;i<=len;i++)
		if(id[ess[i]])totR+=R[by[id[ess[i]]]],totlen+=str[by[id[ess[i]]]].size();
		else{
			int r=0;
			for(j=0;j<ess[i].size();j++)r+=ess[i][j]=='r';
			totR+=r;totlen+=ess[i].size();
		}
	cout<<totR<<" "<<totlen;
	return 0;
}
/*1
3
AbRb r Zz
4
xR abRb
aA xr
zz Z
xr y
*/
/*2
2
RuruRu fedya
1
ruruRU fedor
*/
/*3
10
RRrrRRrrRR abcde rrrrr rrrrr rrrrr RRabc abchh hhhhhhhhhh abrba UURuRr
9
rrrrrrrrrr slfl
slfl ur
abcde r
rrrrr rrabc
rrabc abcrr
abcrr rrabc
abchh hh
hhhhhhhhhh r
abrba abba
*/
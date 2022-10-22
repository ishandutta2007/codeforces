#include <bits/stdc++.h>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void reads(string &s){
	char ch=getchar();s="";
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';s+=ch,ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int T;
string s,wants;
int n,k;
vector<pair<int,int> >ans;
int main(){
	read(T);
	while (T--){
		set <int> st[2];
		wants="";ans.clear();
		read(n),read(k),reads(s);
		for (int i=0;i<n;i++) {
			if (s[i]=='(') st[0].insert(i);
			else st[1].insert(i);
		}
		for (int i=0;i<k-1;i++) wants+="()";
		for (int i=0;i<(n-k*2)/2+1;i++) wants+="(";
		for (int i=0;i<(n-k*2)/2+1;i++) wants+=")";
		for (int i=0;i<n;i++){
			if (s[i]==wants[i]) continue;
			else{
				int go=1;
				if (wants[i]=='(') go=0;
				while (1){
					set<int>::iterator it=st[go].begin();
					if ((*it)<i){
						st[go].erase(it);
					}else{
						swap(s[i],s[(*it)]);
						ans.push_back(make_pair(i+1,(*it)+1));
						st[go^1].insert((*it));
						st[go].erase(it);
						break;
					}
				}
			}
		}
		cout<<ans.size()<<"\n";
		for (int i=0;i<ans.size();i++)
			cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	}
}
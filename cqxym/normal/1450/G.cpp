#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define R register int
#define N 1048576
struct Character{
	char c;
	int lf,rt;
	inline friend bool operator<(Character A,Character B){
		return A.lf<B.lf;
	}
};
int l[N],r[N],ct[N],pos[26];
bool f[N];
int main(){
	int n,a,b;
	cin>>n>>a>>b;
	string s;
	cin>>s;
	for(R i=0;i!=26;i++){
		l[i]=-1;
	}
	for(R i=0;i!=n;i++){
		int v=s[i]-'a';
		if(l[v]==-1){
			l[v]=i;
		}
		r[v]=i;
	}
	vector<Character>C;
	for(R i=0;i!=26;i++){
		if(l[i]!=-1){
			Character Tem;
			Tem.c=i+'a';
			Tem.lf=l[i];
			Tem.rt=r[i];
			C.push_back(Tem);
		}
	}
	sort(C.begin(),C.end());
	int m=C.size();
	for(R i=0;i!=m;i++){
		pos[C[i].c-'a']=i;
	}
	for(R i=0;i!=n;i++){
		ct[1<<pos[s[i]-'a']]++;
	}
	f[0]=true;
	l[0]=5001;
	r[0]=-1;
	for(R i=1;i!=1<<m;i++){
		int S;
		for(R j=0;j!=m;j++){
			if((i>>j&1)==1){
				S=i^1<<j;
				l[i]=l[S];
				r[i]=r[S];
				if(C[j].lf<l[i]){
					l[i]=C[j].lf;
				}
				if(C[j].rt>r[i]){
					r[i]=C[j].rt;
				}
				ct[i]=ct[S]+ct[1<<j];
				break;
			}
		}
		S=0;
		for(R j=0;j!=m;j++){
			if((i>>j&1)==1){
				f[i]|=f[S]&&f[i^S]||f[i^1<<j]&&b*ct[i]>=(r[i]-l[i]+1)*a;
				S|=1<<j;
			}
		}
	}
	vector<char>A;
	for(R i=0;i!=m;i++){
		if(f[(1<<m)-1^1<<i]==true){
			A.push_back(C[i].c);
		}
	}
	cout<<A.size();
	sort(A.begin(),A.end());
	for(vector<char>::iterator T=A.begin();T!=A.end();T++){
		cout<<' '<<*T;
	}
	return 0;
}
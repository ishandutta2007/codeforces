#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=60;
int T,n;
char alpha[MAXN][5];
map<string,pair<ll,pair<string,string> > >f;
ll calc(string s){
	ll ret=0,len=s.length();
	rep(i,0,len-4){
		if(s[i]=='h' && s[i+1]=='a' && s[i+2]=='h' && s[i+3]=='a')ret++;
	}
	return ret;
}
string tmp;
int main(){
	rep(i,0,25)alpha[i][0]='a'+i;
	cin>>T;
	while(T--){
		cin>>n;
		f.clear();
		rep(i,1,n){
			string name,op,x,y;
			name.clear();op.clear();x.clear();y.clear();
			cin>>name>>op;
			if(op==":="){
				cin>>x;
				ll len=x.length(),cnt=calc(x);
				string head,tail;head.clear();tail.clear();
				rep(i,0,Min(len-1,2)){
					head.append(1,x[i]);
				}
				rep(i,Max(len-3,0),len-1){
					tail.append(1,x[i]);
				}
			//	cout<<head<<','<<tail<<endl;
				f[name]=mp(cnt,mp(head,tail));
			}else{
				string tmp;
				cin>>x>>tmp>>y;
				ll cnt1=f[x].fr,cnt2=f[y].fr;
				string head1=f[x].se.fr,head2=f[y].se.fr;
				string tail1=f[x].se.se,tail2=f[y].se.se;
			//	printf("cnt1:%lld cnt2:%lld\n",cnt1,cnt2);
			//	cout<<head1<<','<<head2<<endl;
			//	cout<<cnt1<<','<<cnt2<<endl;
				ll cnt=cnt1+cnt2+calc(tail1+head2);
				string head=head1,tail=tail2;
				int p=0;
				if(i==3){
			//		printf("tmp: %d\n",head.length());
			//		cout<<head<<endl;
				}
				
				while((int)head.length()<3 && p<(int)head2.length()){
					if(i==3){
				//		printf("%c\n",head2[p]);
					}
					head.append(1,head2[p]);
					p++;
				}
			//	cout<<head<<endl;
				p=tail1.length()-1;
				while(tail.length()<3 && p>=0){
					tail=(string)(alpha[tail1[p]-'a'])+tail;
					p--;
				}
				f[name]=mp(cnt,mp(head,tail));
			}
			if(i==n || 0){
				printf("%lld\n",f[name].fr);
			//	cout<<f[name].se.fr<<','<<f[name].se.se<<endl;
			//	cout<<f[name].se.fr.length()<<','<<f[name].se.fr.length()<<endl;
			}
		}
	}

	return 0;
}
/*
1
2
x := haha
x = x + x
*/
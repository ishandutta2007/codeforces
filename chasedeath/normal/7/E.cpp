#include<bits/stdc++.h>
using namespace std;


#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)


//#pragma GCC optimize(2)



const int N=1010,P=998244353;

int n;
map <string,int> M;
string s;
int k[N],fl[N];

int valstk[N],top1,optstk[N],top2;

inline int Add(char op,int id){
	//cout<<"Add operator "<<op<<endl;
	int fl=0;
	if(op=='(') optstk[++top2]=op;
	else if(op==')') {
		//cout<<"!"<<top2<<endl;
		//if(id==3) {
			//puts("#");
			//rep(i,1,top1) cout<<valstk[i]<<endl;
			//puts("\n\n");
		//}
		while(top2 && optstk[top2]!='(') {
			//cout<<"pop operator of kind1  "<<(char)optstk[top2]<<endl;
			if(optstk[top2]=='*') {
				if(valstk[top1]==1||valstk[top1-1]==1) fl=1;
				k[id]=2;
			}
			else if(optstk[top2]=='/') {
				if(valstk[top1-1]==1 || valstk[top1]>=1) fl=1;
				k[id]=2;
			} else {
				if(optstk[top2]=='-') if(valstk[top1]==1) fl=1;
				k[id]=1;
			}
			top2--;
			top1--;
			valstk[top1]=0;
		}
		valstk[top1]=0;
		//cout<<top2<<' '<<(char)optstk[top2+1]<<endl;
		top2--;
		if(top2) {
			//cout<<"!"<<top1<<' '<<top2<<endl;
			//puts("set kind 0");
			k[id]=0;
		}

	} else if(op=='+') {
		while(top2 && optstk[top2]!='(') {
			//cout<<"pop operator of kind2  "<<(char)optstk[top2]<<endl;
			if(optstk[top2]=='*') {
				if(valstk[top1]==1||valstk[top1-1]==1) fl=1;
				k[id]=2;
			}
			else if(optstk[top2]=='/') {
				if(valstk[top1-1]==1 || valstk[top1]>=1) fl=1;
				k[id]=2;
			} else {
				if(optstk[top2]=='-') if(valstk[top1]==1) fl=1;
				k[id]=1;
			}
			top1--,top2--;
			valstk[top1]=0;
		}
		optstk[++top2]=op;
		k[id]=1;
		//puts("set kind 1");

	} else if(op=='-') {
		while(top2 && optstk[top2]!='(') { 
			if(optstk[top2]=='*') {
				if(valstk[top1]==1||valstk[top1-1]==1) fl=1;
				k[id]=2;
			}
			else if(optstk[top2]=='/') {
				if(valstk[top1-1]==1 || valstk[top1]>=1) fl=1;
				k[id]=2;
			} else {
				if(optstk[top2]=='-') if(valstk[top1]==1) fl=1;
				k[id]=1;
			}
			top1--,top2--;
			valstk[top1]=0;
		}
		optstk[++top2]=op;
		k[id]=1;
		//puts("set kind 1");


	} else if(op=='*') {
		while(top2 && optstk[top2]!='(' && optstk[top2]!='+' && optstk[top2]!='-') {
			//cout<<"pop operator of kind3  "<<(char)optstk[top2]<<endl;
			if(optstk[top2]=='*') {
				if(valstk[top1]==1||valstk[top1-1]==1) fl=1;
				k[id]=2;
			}
			else if(optstk[top2]=='/') {
				if(valstk[top1-1]==1 || valstk[top1]>=1) fl=1;
				k[id]=2;
			} else {
				if(optstk[top2]=='-') if(valstk[top1]==1) fl=1;
				k[id]=1;
			}
			top1--,top2--;
			valstk[top1]=0;
		}
		optstk[++top2]=op;
		k[id]=2;
		//puts("set kind 2");

	} else {
		while(top2 && optstk[top2]!='(' && optstk[top2]!='+' && optstk[top2]!='-' ) {
			//cout<<"pop operator of kind4  "<<(char)optstk[top2]<<endl;
			if(optstk[top2]=='*') {
				if(valstk[top1]==1||valstk[top1-1]==1) fl=1;
				k[id]=2;
			}
			else if(optstk[top2]=='/') {
				if(valstk[top1-1]==1 || valstk[top1]>=1) fl=1;
				k[id]=2;
			} else {
				if(optstk[top2]=='-') if(valstk[top1]==1) fl=1;
				k[id]=1;
			}
			top1--,top2--;
			valstk[top1]=0;
		}
		k[id]=2;
		//puts("set kind 2");
		optstk[++top2]=op;
	}
	//cout<<top1<<' '<<top2<<endl;
	return fl;
}

void Addval(string t,int id){
	if(M.count(t)) valstk[++top1]=k[M[t]],fl[id]|=fl[M[t]];
	else valstk[++top1]=0;
	//cout<<"Add Val "<<t<<' '<<valstk[top1]<<' '<<fl[M[t]]<<' '<<fl[id]<<endl;
}




void Get(int id) {
	static char s[110];
	//int t;
	Add('(',id);
	string tmp;
	//while(1) {
		//cout<<s<<' '<<(char)t<<' '<<t<<endl;
		gets(s);
		//cout<<"#"<<s<<endl;
		int len=strlen(s);
		rep(i,0,len-1) {
			if(s[i]==' ') continue;
			if(s[i]=='+'||s[i]=='/'||s[i]=='*'||s[i]=='-'||s[i]=='('||s[i]==')') {
				if(tmp.size()) Addval(tmp,id),tmp.clear();
				fl[id]|=Add(s[i],id);
			}
			else tmp+=s[i];
		}
		if(tmp.size()) Addval(tmp,id);tmp.clear();
		//t=getchar();
		//cout<<(char)t<<' '<<(int)t<<' '<<(int)'\n'<<endl;
		//if(t==EOF||t=='\n') break;
	//}
	fl[id]|=Add(')',id);
	top1=top2=0;
	//cout<<"#"<<top1<<' '<<top2<<endl;
}






int main(){
	//ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	rep(i,1,n) {
		char t;
		do t=getchar();
		while(t!='#');
		cin>>s; 
		//cout<<"#"<<s<<endl;
		cin>>s; 
		//cout<<"#"<<s<<endl;
		Get(M[s]=i);
		//cout<<"i="<<i<<"  "<<k[i]<<' '<<fl[i]<<endl;
	}
	//puts("end define ");
	Get(++n);
	puts(fl[n]?"Suspicious":"OK");
}
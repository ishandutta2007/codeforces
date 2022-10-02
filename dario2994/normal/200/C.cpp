#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string nomi[4];
int ris[4][4][2];
int done[4];
int pp[4],dd[4],ss[4];

int in(string s){
	for(int i=0;i<4;i++){
		if(nomi[i]==s)return i;
		if(nomi[i]=="ciaoaoaoaoaoa"){
			nomi[i]=s;
			return i;
		}
	}
	return 0;
}

bool compare(int a,int b){
	if(pp[a]<pp[b])return true;
	if(pp[a]>pp[b])return false;
	if(dd[a]<dd[b])return true;
	if(dd[a]>dd[b])return false;
	if(ss[a]<ss[b])return true;
	if(ss[a]>ss[b])return false;
	if(nomi[a]>nomi[b])return true;
	if(nomi[a]<nomi[b])return false;
	return false;
}

void init(){
	for(int v=0;v<4;v++){
		pp[v]=0;
		dd[v]=0;
		ss[v]=0;
		for(int i=0;i<4;i++){
			if(i==v)continue;
			int io=ris[v][i][0];
			int tu=ris[v][i][1];
			if(io>tu)pp[v]+=3;
			if(io==tu)pp[v]+=1;
			if(io<tu)pp[v]+=0;
			dd[v]+=io-tu;
			ss[v]+=io;
		}
	}
}

using namespace std;
int main(){
	for(int i=0;i<4;i++)nomi[i]="ciaoaoaoaoaoa";
	for(int i=0;i<5;i++){
		string n1,n2;
		cin >> n1 >> n2;
		int r1=in(n1);
		int r2=in(n2);
		int a1,a2;
		char xx;
		cin >> a1 >> xx >> a2;
		done[r1]++;
		done[r2]++;
		ris[r1][r2][0]=a1;
		ris[r1][r2][1]=a2;
		ris[r2][r1][0]=a2;
		ris[r2][r1][1]=a1;
	}
	//~ for(int i=0;i<4;i++){
		//~ for(int j=0;j<4;j++)cout << ris[i][j][0] <<":"<<ris[i][j][1] << " ";
		//~ cout << endl;
	//~ }
	int A=in("BERLAND");
	int B;
	for(int i=0;i<4;i++)if(done[i]<3 and i!=A)B=i;
	for(int d=1;d<70;d++){
		for(int y=0;y<70;y++){
			int x=y+d;
			ris[A][B][0]=x;
			ris[A][B][1]=y;
			ris[B][A][0]=y;
			ris[B][A][1]=x;
			int nn[4]={0,1,2,3};
			init();
			sort(nn,nn+4,compare);
			if(nn[2]==A or nn[3]==A){
				cout << x << ":" << y;
				return 0;
			} 
		}
	}
	cout << "IMPOSSIBLE";
}
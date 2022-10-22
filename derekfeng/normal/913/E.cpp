#include<bits/stdc++.h>
using namespace std;
const int Mx=10;
void upd(string &s,string t){
	if(s.empty())s=t;
	else if(s.size()>t.size())s=t;
	else if(s.size()==t.size()&&s>t)s=t;
}
string f[12][260][3];
void init(){
	f[0][0b00001111][2]="x";
	f[0][0b00110011][2]="y";
	f[0][0b01010101][2]="z";
	for(int i=0;i<Mx;i++){
		for(int j=0;j<256;j++){
			if(!f[i][j][0].empty())upd(f[i+1][j][0],f[i][j][0]);
			if(!f[i][j][1].empty())upd(f[i+1][j][1],f[i][j][1]);
			if(!f[i][j][2].empty())upd(f[i+1][j][2],f[i][j][2]);
			if(!f[i][j][0].empty())upd(f[i+1][j][2],"("+f[i][j][0]+")");
			if(!f[i][j][1].empty())upd(f[i+1][j][2],"("+f[i][j][1]+")");
			if(!f[i][j][2].empty())upd(f[i+1][j][2],"("+f[i][j][2]+")");
			if(!f[i][j][2].empty())upd(f[i+1][j^255][2],"!"+f[i][j][2]);
		}
		for(int j=0;j<256;j++)for(int k=0;k<256;k++){
			if(!f[i][j][0].empty()&&!f[i][k][1].empty())upd(f[i+1][j|k][0],f[i][j][0]+"|"+f[i][k][1]);
			if(!f[i][j][0].empty()&&!f[i][k][2].empty())upd(f[i+1][j|k][0],f[i][j][0]+"|"+f[i][k][2]);
			if(!f[i][j][1].empty()&&!f[i][k][1].empty())upd(f[i+1][j|k][0],f[i][j][1]+"|"+f[i][k][1]);
			if(!f[i][j][1].empty()&&!f[i][k][2].empty())upd(f[i+1][j|k][0],f[i][j][1]+"|"+f[i][k][2]);
			if(!f[i][j][2].empty()&&!f[i][k][1].empty())upd(f[i+1][j|k][0],f[i][j][2]+"|"+f[i][k][1]);
			if(!f[i][j][2].empty()&&!f[i][k][2].empty())upd(f[i+1][j|k][0],f[i][j][2]+"|"+f[i][k][2]);
			if(!f[i][j][1].empty()&&!f[i][k][2].empty())upd(f[i+1][j&k][1],f[i][j][1]+"&"+f[i][k][2]);
			if(!f[i][j][2].empty()&&!f[i][k][2].empty())upd(f[i+1][j&k][1],f[i][j][2]+"&"+f[i][k][2]);
		}
	}
}
int T;
int main(){
	init();
	scanf("%d",&T);
	while(T--){
		string ans="";
		char buf[10];
		scanf("%s",buf);
		int msk=0;
		for(int i=0;i<8;i++)msk=(msk<<1)+buf[i]-'0';
		for(int i=0;i<3;i++)upd(ans,f[Mx][msk][i]);
		printf("%s\n",ans.c_str());
	}
}